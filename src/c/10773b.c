// 백준 10773번 문제 : 제로
// https://www.acmicpc.net/problem/10773
// 알고리즘 분류 : 구현, 자료 구조, 문자열, 스택

// 배열 기반 스택

#include <stdio.h>
#include <stdlib.h>

int sp = -1;
int push(int* stack, const int data);
int pop(int* stack);

int main(void)
{
    int k;
    int input;
    int total = 0;

    scanf("%d", &k);
    getchar();
    int* stk = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &input);
        if (sp != -1 && !input)
            pop(stk);
        else push(stk, input);
    }
    while (sp != -1)
        total += pop(stk);
    printf("%d\n", total);

    free(stk);
    return 0;
}

int push(int* stack, const int data)
{
    stack[++sp] = data;
    return 0;
}

int pop(int* stack)
{
    return stack[sp--];
}