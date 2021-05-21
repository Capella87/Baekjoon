// 백준 1918번 문제 : 후위 표기식
// https://www.acmicpc.net/problem/1918
// 알고리즘 분류 : 자료 구조, 스택

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char Data;
typedef int Top;

typedef struct _stack
{
    Data stk[101];
    Top t;
} Stack;

bool initStack(Stack* stk)
{
    stk->t = -1;
    return true;
}

bool isEmpty(const Stack* stk)
{
    return stk->t == -1 ? true : false;
}

bool push(Stack* s, const Data d)
{
    s->stk[++s->t] = d;
    return true;
}
Data pop(Stack* s)
{
    if (isEmpty(s)) return -1;
    return s->stk[s->t--];
}
Data peek(const Stack* s)
{
    if (isEmpty(s)) return -1;
    return s->stk[s->t];
}

int main(void)
{
    Data input[101];
    Data* pos = input;
    Stack stk;
    initStack(&stk);

    scanf("%[^\n]", input);
    size_t len = strlen(input);
    for (; pos < input + len; pos++)
    {
        if (*pos >= 'A' && *pos <= 'Z') // 피연산자
        {
            putchar(*pos);
            continue;
        }
        switch (*pos) // 연산자
        {
        case '(':
            push(&stk, *pos);
            break;
        case ')':
            while (!isEmpty(&stk) && peek(&stk) != '(')
                printf("%c", pop(&stk));
            pop(&stk);
            break;
        case '+':
        case '-':
            while (!isEmpty(&stk) && peek(&stk) != '(') // 자신보다 연산 우선순위가 높거나 같은 게 스택에 있으면 출력
                printf("%c", pop(&stk));
            push(&stk, *pos);
            break;  
        case '*':
        case '/':
            while (!isEmpty(&stk) && strchr("*/", peek(&stk)))
                printf("%c", pop(&stk)); // 이것 역시 자신보다 우선순위가 높거나 같은 것이 있으면 출력 (여기서는 */ 위 연산자 없음)
            push(&stk, *pos);
            break;
        }
    }
    while (!isEmpty(&stk))
        printf("%c", pop(&stk));
    putchar('\n');

    return 0;
}