// 백준 1977번 문제 : 완전제곱수
// https://www.acmicpc.net/problem/1977
// 알고리즘 분류 : 수학, 구현

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n;
    int total = 0, min = 0;

    cin >> m >> n;
    for (int i = int(sqrt(m)); i <= int(sqrt(n)); i++)
    {
        int temp = i * i;
        if (temp >= m && temp <= n)
        {
            if (!total) min = temp;
            total += temp;
        }
    }
    if (!total) cout << "-1\n";
    else cout << total << '\n' << min << '\n';

    return 0;
}