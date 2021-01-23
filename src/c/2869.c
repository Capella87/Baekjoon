// 백준 2869번 문제 : 달팽이는 올라가고 싶다
// https://www.acmicpc.net/problem/2869

#include <stdio.h>

int main(void)
{
    int a, b, v;
    int result;

    scanf("%d %d %d", &a, &b, &v);
    result = (v - b) % (a - b) == 0 ? (v - b) / (a - b) : (v - b) / (a - b) + 1;
    printf("%d\n", result);

    return 0;
}