// 백준 19638번 문제 : 센티와 마법의 뿅망치
// https://www.acmicpc.net/problem/19638
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 우선순위 큐

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int> giants;
    int n, h, t, count = 0;

    cin >> n >> h >> t;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        giants.push(temp);
    }

    while (t > 0)
    {
        int temp = giants.top();
        if (temp > 1 && temp >= h)
        {
            temp /= 2;
            giants.pop();
            giants.push(temp);
        }
        else break;
        count++;
        t--;
    }

    if (giants.top() >= h)
        cout << "NO" << '\n' << giants.top() << '\n';
    else
        cout << "YES" << '\n' << count << '\n';

    return 0;
}