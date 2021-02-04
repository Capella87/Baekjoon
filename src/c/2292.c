// 백준 2292번 문제 : 벌집
// https://www.acmicpc.net/problem/2292
// 알고리즘 분류 : 수학

#include <stdio.h>

int main(void)
{
    int input;
    int result = 1, i = 1;

    scanf("%d", &input);

    while (3 * i * i - 3 * i + 1 < input) // 점화식
    {
        result++;
        i++;
    }
    printf("%d\n", result);

    return 0;
}