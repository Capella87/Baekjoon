// 백준 4153번 문제 : 직각삼각형
// https://www.acmicpc.net/problem/4153

#include <stdio.h>

int main(void)
{
    int a, b, c;

    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
            puts("right");
        else puts("wrong");
    }
    
    return 0;
}