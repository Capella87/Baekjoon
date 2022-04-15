// 백준 10942번 문제 : 팰린드롬?
// https://www.acmicpc.net/problem/10942
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <iostream>
using namespace std;

int n, m, from, to;
int arr[2000];
bool cache[2000][2000]{ false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> arr[0];
    cache[0][0] = true;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        cache[i][i] = true;
        cache[i - 1][i] = arr[i - 1] == arr[i] ? true : false;
        for (int j = i - 2; j >= 0; j--)
            cache[j][i] = (cache[j + 1][i - 1] && arr[j] == arr[i]) ? true : false;
    }
    cin >> m;
    while (m > 0)
    {
        cin >> from >> to;
        cout << (int)cache[from - 1][to - 1] << '\n';
        m--;
    }

    return 0;
}