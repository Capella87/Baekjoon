// 백준 2559번 문제 : 수열
// https://www.acmicpc.net/problem/2559
// 알고리즘 분류 : 누적 합, 두 포인터

#include <stdio.h>

int arr[100000] = { 0, };

int main(void)
{
    int n, k;
    int pre_sum = 0;
    int max = 0;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i < k)
        {
            pre_sum += arr[i];
            max = pre_sum;
        }
        else
        {
            pre_sum -= arr[i - k];
            pre_sum += arr[i];
            if (max < pre_sum)
                max = pre_sum;
        }
    }
    printf("%d\n", max);
    
    return 0;
}