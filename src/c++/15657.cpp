// 백준 15657번 문제 : N과 M (8)
// https://www.acmicpc.net/problem/15657
// 알고리즘 분류 : 백트래킹

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;
int* arr = NULL;
int* workingset = NULL;

void backtracking(int idx, int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++) printf("%d ", workingset[i]);
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (idx == -1 || arr[i] >= workingset[count - 1])
        {
            workingset[count++] = arr[i];
            backtracking(i, count);
            count--;
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    arr = (int*)calloc(n, sizeof(int));
    workingset = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    backtracking(-1, 0);

    free(arr);
    free(workingset);
    return 0;
}
