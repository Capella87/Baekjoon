// 백준 5543번 문제 : 상근날드
// https://www.acmicpc.net/problem/5543
// 알고리즘 분류 : 수학, 사칙연산

#include <stdio.h>

int main(void)
{
    int burgers[3];
    int beverages[2];
    int result[6];
    int* min = result;
    int i, j;

    for (i = 0; i < 3; i++)
        scanf("%d", burgers + i);
    for (i = 0; i < 2; i++)
        scanf("%d", beverages + i);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i * 2 + j] = burgers[i] + beverages[j] - 50;
            if (result[i * 2 + j] < *min)
                min = result + i * 2 + j;
        }
    }
    printf("%d\n", *min);

    return 0;
}