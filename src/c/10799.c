// 백준 10799번 문제 : 쇠막대기
// https://www.acmicpc.net/problem/10799
// 알고리즘 분류 : 자료 구조, 스택

// 규칙 찾아내기

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Data;
typedef struct _stack
{
    Data* stk;
    int t;
} Stack;

bool initStack(Stack* s, const size_t len)
{
    s->stk = (Data*)malloc(sizeof(Data) * len);
    if (!s->stk) return false;
    s->t = -1;

    return true;
}

size_t size(const Stack* s)
{
    return s->t + 1;
}

bool isEmpty(const Stack* s)
{
    return s->t == -1 ? true : false;
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

int main(void)
{
    char input[100001];
    size_t len;
    Stack s;

    scanf("%[^\n]", input);
    len = strlen(input);
    initStack(&s, len);
    char* prev = input;
    int fragment = 0;

    for (char* pos = input; pos < input + len; pos++)
    {
        if (*pos == '(')
            push(&s, *pos);
        else if (*prev == '(' && *pos == ')') // 레이저인 경우
        {
            pop(&s);
            fragment += size(&s);
        }
        else if (*prev == ')' && *pos == ')') // 막대기 끝인 경우 그 기준에서 가장 나중에 나온 막대기 쪼갠 것 하나만 더한다.
        {
            pop(&s);
            fragment++;
        }
        prev = pos;
    }
    printf("%d\n", fragment);

    free(s.stk);
    return 0;
}