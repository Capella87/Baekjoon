// 백준 5622번 문제 : 다이얼
// https://www.acmicpc.net/problem/5622
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[16];
    int i;
    int time = 0;

    scanf("%s", &input);
    getchar();
    

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'C')
            time += 3;
        else if (input[i] >= 'D' && input[i] <= 'F')
            time += 4;
        else if (input[i] >= 'G' && input[i] <= 'I')
            time += 5;
        else if (input[i] >= 'J' && input[i] <= 'L')
            time += 6;
        else if (input[i] >= 'M' && input[i] <= 'O')
            time += 7;
        else if (input[i] >= 'P' && input[i] <= 'S')
            time += 8;
        else if (input[i] >= 'T' && input[i] <= 'V')
            time += 9;
        else if (input[i] >= 'W' && input[i] <= 'Z')
            time += 10;
    }
    printf("%d\n", time);

    return 0;
}