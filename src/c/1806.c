// 백준 1806번 문제 : 부분합
// https://www.acmicpc.net/problem/1806
// 알고리즘 분류 : 두 포인터

#include <stdio.h>

int arr[100000];

int main(void)
{
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int* start = arr;
    int* end = arr;
    int min = 0, total = 0;
    
    for (end = arr; end < arr + n; end++)
    {
        total += *end;
        if (total < s) continue;
        while ((total - *start) >= s && start <= end)
        {
            total -= *start;
            if (start == end) break;
            else start++;
        }
        if (!min || (end - start + 1) < min)
            min = (int)(end - start) + 1;
    }
    printf("%d\n", min);
    
    return 0;
}