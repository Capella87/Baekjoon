// 백준 2118번 문제 : 두 개의 탑
// https://www.acmicpc.net/problem/2118
// 알고리즘 분류 : 누적 합, 두 포인터

#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int arr[50000];

int main(void)
{
    int n, total = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    int start = 1, end = 0;
    int front_dist = arr[start] + arr[end];
    int back_dist = total - front_dist, max = -1;

    while (start < n)
    {
        if (front_dist < back_dist)
        {
            max = MAX(max, front_dist);
            if (++start < n)
            {
                front_dist += arr[start];
                back_dist -= arr[start];
            }
        }
        else
        {
            max = MAX(max, back_dist);
            front_dist -= arr[end];
            back_dist += arr[end++]; // Don't have to care about end == start.
            // Because when the end and the start are the same, start pointer must go foward.
        }
    }
    printf("%d\n", max);

    return 0;
}