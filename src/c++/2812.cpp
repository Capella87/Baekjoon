// 백준 2812번 문제 : 크게 만들기
// https://www.acmicpc.net/problem/2812
// 알고리즘 분류 : 자료 구조, 그리디 알고리즘, 스택

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    string num;
    int remove_count = 0;
    deque<char> deq;

    cin >> n >> k;
    cin.get();
    getline(cin, num);
    int size = (int)num.length();

    deq.push_back(num[0]);
    for (int i = 1; i < size; i++)
    {
        while (!deq.empty() && k > 0 && deq.back() < num[i])
        {
            deq.pop_back();
            k--;
        }
        deq.push_back(num[i]);
    }
    size = (int)deq.size() - k;
    for (int i = 0; i < size; i++)
        cout << deq[i];
    cout << '\n';

    return 0;
}