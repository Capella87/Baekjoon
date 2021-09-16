// 백준 6119번 문제 : Cow Line
// https://www.acmicpc.net/problem/6119
// 알고리즘 분류 : 자료 구조, 덱

#include <iostream>
#include <deque>
using namespace std;

void addCow(deque<int>& target, const char side, int* count)
{
    switch (side)
    {
    case 'L':
        target.push_front(*count);
        break;
    case 'R':
        target.push_back(*count);
        break;
    }
    (*count)++;
}

void removeCow(deque<int>& target, const char side, const int k)
{
    int i = 0;
    if (side == 'L')
    {
        while (i < k && !target.empty())
        {
            target.pop_front();
            i++;
        }
    }
    else
    {
        while (i < k && !target.empty())
        {
            target.pop_back();
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    deque <int> cows;
    int n, k, count = 1;
    char command, side;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command >> side;
        if (command == 'D')
        {
            cin >> k;
            removeCow(cows, side, k);
        }
        else addCow(cows, side, &count);
        cin.get();
    }
    while (!cows.empty())
    {
        cout << cows.front() << '\n';
        cows.pop_front();
    }
    return 0;
}