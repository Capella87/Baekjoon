// 백준 3052번 문제 : 나머지
// https://www.acmicpc.net/problem/3052

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int list[10];
    int i, j, count = 0;
    bool diff = true;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", list + i);
        getchar();
        *(list + i) = list[i] % 42;
        diff = true;
        for (j = 0; j < i; j++)
        {
            if (list[j] == list[i])
            {
                diff = false;
                break;
            }
        }
        if (diff) count++;
    }
    printf("%d\n", count);

    return 0;
}