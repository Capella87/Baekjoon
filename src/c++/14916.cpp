// 백준 14916번 문제 : 거스름돈
// https://www.acmicpc.net/problem/14916
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 그리디 알고리즘

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // Greedy algorithm
    int n;
    cin >> n;
    int count = -1;

    if ((n % 5) % 2 == 0)
    {
        count = (n / 5) + ((n % 5) / 2);
    }
    else if (n != 1 && n != 3)
    {
        count = (n / 5 - 1) + ((n % 5) + 5) / 2;
    }
    cout << count << '\n';
    return 0;
}
