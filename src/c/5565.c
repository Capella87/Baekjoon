// 백준 5565번 문제 : 영수증
// https://www.acmicpc.net/problem/5565
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <stdio.h>

int main(void)
{
    int temp, total;

    scanf("%d", &total);
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &temp);
        total -= temp;
    }
    printf("%d", total);
    return 0;
}