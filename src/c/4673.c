// 백준 4673번 문제 : 셀프 넘버
// https://www.acmicpc.net/problem/4673

#include <stdio.h>
#include <stdbool.h>
#define INPUT 10000

bool list[10040] = { false, };

void GetSelfNum(int);

int main(void)
{
    GetSelfNum(INPUT);
    return 0;
}

void GetSelfNum(int max)
{
    int pos;
    int result, temp;
    
    for (pos = 1; pos <= max; pos++)
    {
        temp = pos;
        result = temp;
        while (temp != 0)
        {
            result += (temp % 10);
            temp /= 10;
        }
        list[result] = true;
    }
    for (pos = 1; pos <= max; pos++)
        if (list[pos] == false)
            printf("%d\n", pos);
}