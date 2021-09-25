// 백준 18115번 문제 : 카드 놓기
// https://www.acmicpc.net/problem/18115
// 알고리즘 분류 : 자료 구조, 덱

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    deque<int> cards;
    int n, j = 1, temp;

    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 1) cards.push_front(j++);
        else if (arr[i] == 2 && cards.size() > 1)
        {
            int temp = cards.front();
            cards.pop_front();
            cards.push_front(j++);
            cards.push_front(temp);
        }
        else cards.push_back(j++);
    }
    while (!cards.empty())
    {
        cout << cards.front() << ' ';
        cards.pop_front();
    }
    cout << '\n';
    delete[] arr;
    return 0;
}