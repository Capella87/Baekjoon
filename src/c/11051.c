// 백준 11051번 문제 : 이항 계수 2
// https://www.acmicpc.net/problem/11051
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

uint64_t binomial(int n, int k)
{
    if (k > (n / 2)) k = n - k;

    uint64_t* arr = (uint64_t*)malloc(sizeof(uint64_t) * (k + 1));
    memset((void*)arr, 0L, sizeof(uint64_t) * (k + 1));
    arr[0] = 1L;

    // Use modulo property; (a + b)mod n = (a mod n + b mod n) mod n
    for (int i = 1; i < n + 1; i++)
    {
        int j = MIN(i, k);
        while (j > 0)
        {
            arr[j] = ((arr[j] % 10007) + (arr[j - 1] % 10007)) % 10007;
            j--;
        }
    }

    uint64_t rt = arr[k];
    free(arr);
    return rt;
}

int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);
    printf("%llu\n", binomial(n, k) % 10007);

    return 0;
}