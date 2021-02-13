// 백준 2960번 문제 : 에라스토테네스의 체
// https://www.acmicpc.net/problem/2960
// 알고리즘 분류 : 수학, 구현, 정수론, 소수 판정, 에라스토테네스의 체

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int erastos(int n, int k);

int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);
    printf("%d\n", erastos(n, k));

    return 0;
}

int erastos(int n, int k)
{
    int i, j;
    int deleteCount = 0;
    bool* list = NULL;

    list = (bool*)calloc(n + 1, sizeof(bool));
    for (i = 2; i <= n; i++)
    {
        if (list[i] == true) continue;
        for (j = i; j * j <= n * n; j += i)
        {
            if (j % i == 0 && list[j] == false)
            {
                list[j] = true;
                ++deleteCount;
            }
            if (deleteCount == k)
            {
                free(list);
                return j;
            }
        }
    }
}