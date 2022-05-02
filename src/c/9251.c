// 백준 9251번 문제 : LCS
// https://www.acmicpc.net/problem/9251
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
#include <string.h>
#define MAX 1000

char a[MAX + 1];
char b[MAX + 1];
int cache[MAX + 1][MAX + 1] = { 0, };

int main(void)
{
    scanf("%[^\n]", &a);
    getchar();
    scanf("%[^\n]", &b);
    
    // Bottom-up
    int a_size = (int)strlen(a);
    int b_size = (int)strlen(b);
    for (int i = 1; i <= a_size; i++)
    {
        for (int j = 1; j <= b_size; j++)
        {
            if (a[i - 1] == b[j - 1]) // Same character -> Add count
                cache[i][j] = cache[i - 1][j - 1] + 1;
            else cache[i][j] = cache[i - 1][j] > cache[i][j - 1] ? cache[i - 1][j] : cache[i][j - 1];
        }
    }
    printf("%d\n", cache[a_size][b_size]);

    return 0;
}