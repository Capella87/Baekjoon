// 백준 2839번 문제 : 설탕 배달
// https://www.acmicpc.net/problem/2839
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 그리디 알고리즘

#include <stdio.h>

int main(void)
{
    int three = 0, five = 0;
    int n;

    scanf("%d", &n);

    // 일단 5로 나누어 본다.
    five = n / 5;
    n %= 5;

    while (five >= 0)
    {
        if (n % 3 == 0) // 남은 값들이 3으로 나누어 떨어지는 경우
        {
            three = n / 3;
            n %= 3;
            break;
        }
        five--; // 5로 나누었던 것을 해제해 본다.
        n += 5;
    }
    printf("%d\n", (n == 0) ? three + five : -1); // 5 또는 3으로 나누어 떨어진 경우 합산

    return 0;
}