// 백준 9012번 문제 : 괄호
// https://www.acmicpc.net/problem/9012
// 알고리즘 분류 : 자료 구조, 문자열, 스택

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50

typedef char Data;
typedef char Stack;

int t = -1;

bool push(Stack*, const Data);
Data pop(Stack*);

int main(void)
{
    int n;
    char temp[MAX + 1], * pos = NULL, t2;
    bool violent;
    size_t len;
    Stack stk[MAX] = "";

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", temp);
        getchar();
        len = strlen(temp);
        violent = false;
        for (pos = temp; pos < temp + len; pos++)
        {
            if (*pos == '(')
                push(stk, *pos);
            else
            {
                t2 = pop(stk);
                if (t2 == -1)
                {
                    violent = true;
                    break;
                }
            }
        }
        if (violent || t != -1) puts("NO");
        else puts("YES");
        t = -1;
    }

    return 0;
}

bool push(Stack* stk, const Data d)
{
    if (t + 1 > MAX) return false;

    stk[++t] = d;
    return true;
}
Data pop(Stack* stk)
{
    if (t == -1) return -1;

    return stk[t--];
}