// 백준 1094번 문제 : 막대기
// https://www.acmicpc.net/problem/1094
// 알고리즘 분류 : 수학, 비트마스킹

#include <stdio.h>

int main(void)
{
    int x, count = 0;

    scanf("%d", &x);
    while (x != 0)
    {
        if (x & 1) // x의 마지막 이진수 자리가 1이면 센다.
            count++;
        x >>= 1; // 판별한 마지막 자리를 밀어서 제거 (right shift)
    }
    printf("%d\n", count); // 이진수 값에서의 1의 값

    return 0;
}