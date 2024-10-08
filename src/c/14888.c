// 백준 14888번 문제 : 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888
// 알고리즘 분류 : 브루트포스 알고리즘, 백트래킹

// Brute-Force Algorithm

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void search_values(int n, int* arr, int* operations, int* status, int idx, int prev)
{
    if (idx == (n - 1))
    {
        status[0] = MAX(status[0], prev);
        status[1] = MIN(status[1], prev);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operations[i] == 0) continue;
        int temp;

        operations[i]--;
        switch (i)
        {
        case 0:
            search_values(n, arr, operations, status, idx + 1, prev + arr[idx + 1]);
            break;
        case 1:
            search_values(n, arr, operations, status, idx + 1, prev - arr[idx + 1]);
            break;
        case 2:
            search_values(n, arr, operations, status, idx + 1, prev * arr[idx + 1]);
            break;
        case 3:
            if (prev < 0) temp = (abs(prev) / arr[idx + 1]) * -1;
            else temp = prev / arr[idx + 1];
            search_values(n, arr, operations, status, idx + 1, temp);
        }
        operations[i]++;
    }
}

int* solve(int n, int* arr, int* operations)
{
    int* results = (int*)malloc(sizeof(int) * 2);
    results[0] = -1000000000;
    results[1] = 1000000000;

    search_values(n, arr, operations, results, 0, arr[0]);
    return results;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    int operations[4] = { 0, };

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &operations[i]);
    }
    int* results = solve(n, arr, operations);
    for (int i = 0; i < 2; i++)
        printf("%d\n", results[i]);

    free(arr);
    free(results);
    return 0;
}
