// 백준 2161번 문제 : 카드1
// https://www.acmicpc.net/problem/2161
// 알고리즘 분류 : 구현, 자료 구조, 덱, 큐

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    deque <int>deck;
    for (int i = 1; i <= n; i++)
        deck.push_back(i);
    while (deck.size() > 1)
    {
        cout << deck.front() << ' ';
        deck.pop_front();
        int temp = deck.front();
        deck.pop_front();
        deck.push_back(temp);
    }
    cout << deck.front() << '\n';
    return 0;
}