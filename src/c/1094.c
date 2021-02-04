// 백준 1094번 문제 : 막대기
// https://www.acmicpc.net/problem/1094
// 알고리즘 분류 : 수학, 비트마스킹

#include <stdio.h>

int main(void)
{
    int input;
    int count = 0;
    
    scanf("%d", &input);
    while (input != 0)
    {
        if (input % 2 == 1)
            count++;
        input /= 2;
    }
    printf("%d\n", count);
    
    return 0;
}