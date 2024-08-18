// 백준 13707번 문제 : 합분해 2
// https://www.acmicpc.net/problem/13707
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론

#include <stdio.h>
#include <stdint.h>
#define MAX 5000
#define DIV 1000000000

int n, k;
uint64_t arr[MAX][MAX + 1];

int main(void)
{
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i <= n; i++)
        arr[0][i] = 1;
    for (int i = 1; i < k; i++)
        arr[i][0] = 1;
    for (int i = 1; i < k; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % DIV;
    // S(n, k) = S(0, k - 1) + S(1, k - 1) + ... + S(n, k - 1);
    printf("%llu\n", arr[k - 1][n]);
    
    return 0;
}
