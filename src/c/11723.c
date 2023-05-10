// 백준 11723번 문제 : 집합
// https://www.acmicpc.net/problem/11723
// 알고리즘 분류 : 구현, 비트마스킹

#include <stdio.h>
#include <string.h>

char set[20];

void add(const int x)
{
    if (set[x - 1] == '0')
        set[x - 1] = '1';
}

void remove_element(const int x)
{
    if (set[x - 1] == '1')
        set[x - 1] = '0';
}

void check(const int x)
{
    if (set[x - 1] == '1') puts("1");
    else puts("0");
}

void toggle(const int x)
{
    if (set[x - 1] == '1') set[x - 1] = '0';
    else set[x - 1] = '1';
}

int main(void)
{
    int m, target;
    char input[10] = "";
    memset((char*)set, '0', sizeof(char) * 20);
    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; i++)
    {
        scanf("%s", &input);
        if (!strcmp(input, "add"))
        {
            scanf("%d", &target);
            add(target);
        }
        else if (!strcmp(input, "check"))
        {
            scanf("%d", &target);
            check(target);
        }
        else if (!strcmp(input, "remove"))
        {
            scanf("%d", &target);
            remove_element(target);
        }
        else if (!strcmp(input, "toggle"))
        {
            scanf("%d", &target);
            toggle(target);
        }
        else if (!strcmp(input, "all")) memset((char*)set, '1', sizeof(char) * 20);
        else if (!strcmp(input, "empty")) memset((char*)set, '0', sizeof(char) * 20);
        getchar();
    }

    return 0;
}