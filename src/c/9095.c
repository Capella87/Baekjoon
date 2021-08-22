// 백준 9095번 문제 : 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
// 이 문제는 점화식을 이용하여 재귀 함수로 구현해 풀 수도 있다.
// 점화식 A(n) = A(n - 1) + A(n - 2) + A(n - 3)

int getCase(int input)
{
    if (input <= 2) return input;
    else if (input == 3) return 4;
    else return getCase(input - 1) + getCase(input - 2) + getCase(input - 3);
}

int main(void)
{
    int n, input;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        printf("%d\n", getCase(input));
    }
    return 0;
}