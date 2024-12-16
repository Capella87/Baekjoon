// 백준 2302번 문제 : 극장 좌석
// https://www.acmicpc.net/problem/2302
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, start = 0, diff = 0, total = 1, x = 1;
    cin >> n >> m;
    int* cache = new int[41];
    cache[0] = 0; cache[1] = 1; cache[2] = 2;
    for (int i = 3; i <= 40; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        diff = x - start - 1;
        if (diff > 0) total *= cache[diff];
        start = x;
    }
    diff = n - start;
    if (diff > 0) total *= cache[diff];
    cout << total << '\n';

    delete[] cache;
    return 0;
}
