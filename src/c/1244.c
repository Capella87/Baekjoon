// 백준 1244번 문제 : 스위치 켜고 끄기
// https://www.acmicpc.net/problem/1244
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <stdlib.h>

int updateSwitch(int* arr, const int count, const int gender, const int input);
void toggle(int* arr, const int num);
void print(const int* arr, const int num);

int main(void)
{
    int sCount, stuCount, gender, n;

    scanf("%d", &sCount);
    int* swit = (int*)malloc(sizeof(int) * sCount);
    for (int i = 0; i < sCount; i++)
        scanf("%d", &swit[i]);
    getchar();
    scanf("%d", &stuCount);
    for (int i = 0; i < stuCount; i++)
    {
        scanf("%d %d", &gender, &n);
        updateSwitch(swit, sCount, gender, n);
    }
    print(swit, sCount);
    free(swit);
    return 0;
}

void print(const int* arr, const int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
}

int updateSwitch(int* arr, const int count, const int gender, const int input)
{
    int i = 1;
    if (count < input || input <= 0) return -1;
    switch (gender)
    {
    case 1:
        while (input * i <= count)
            toggle(arr, input * i++);
        break;
    case 2:
        toggle(arr, input);
        while ((input - i) > 0 && (input + i) <= count && arr[input - i - 1] == arr[input + i - 1])
        {
            toggle(arr, input - i);
            toggle(arr, input + i++);
        }
        break;
    }

    return 0;
}

void toggle(int* arr, const int num)
{
    if (arr[num - 1]) arr[num - 1] = 0;
    else arr[num - 1] = 1;
}