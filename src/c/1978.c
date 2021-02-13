// 백준 1978번 문제 : 소수 찾기
// https://www.acmicpc.net/problem/1978
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라스토테네스의 체

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool getPrime(int);

int main(void)
{
    int n;
    int primeCount = 0;
    int* temp = NULL;

    scanf("%d", &n);
    getchar();
    temp = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", temp + i);
        getchar();
        if (getPrime(*(temp + i)) == true) primeCount++;
    }
    printf("%d\n", primeCount);
    free(temp);

    return 0;
}

bool getPrime(int input)
{
    int i;

    if (input == 1) return false;
    for (i = 2; i * i <= input * input; i++)
        if (input % i == 0 && input != i)
            return false;

    return true;
}