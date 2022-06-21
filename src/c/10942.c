// 백준 10942번 문제 : 팰린드롬?
// https://www.acmicpc.net/problem/10942
// 알고리즘 분류 : 다이나믹 프로그래밍, 문자열

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int n, m, s, e;
    bool isPalindrome = false;
    int* lists = NULL, *pos = NULL, *pos2 = NULL;

    scanf("%d", &n);
    getchar();
    lists = (int*)malloc(sizeof(int) * n);
    if (lists == NULL) exit(EXIT_FAILURE);
    for (pos = lists; pos < lists + n; pos++)
        scanf("%d", pos);
    getchar();
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &e);
        isPalindrome = true;
        getchar();
        if (e - s > 1)
        {
            for (pos = lists + s - 1, pos2 = lists + e - 1; pos < (s + e) / 2 - 1; pos++, pos2--)
            {
                if (*pos != *pos2)
                {
                    isPalindrome = false;
                    break;
                }
            }
        }
        printf("%d\n", (int)isPalindrome);
    }
    free(lists);
    return 0;
}