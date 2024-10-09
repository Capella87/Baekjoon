// 백준 15656번 문제 : N과 M (7)
// https://www.acmicpc.net/problem/15656
// 알고리즘 분류 : 백트래킹

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void explore(int level, vector<int>& sequence, vector<int>& status)
{
    if ((level + 1) == m)
    {
        for (int i = 0; i < n; i++)
        {
            status[level] = sequence[i];
            for (int j = 0; j < m; j++)
                printf("%d ", status[j]);
            putchar('\n');
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        status[level] = sequence[i];
        explore(level + 1, sequence, status);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    vector<int> sequence(n);
    vector<int> status(m);

    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    sort(sequence.begin(), sequence.end());
    explore(0, sequence, status);
    return 0;
}
