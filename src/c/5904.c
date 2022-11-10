// 백준 5904번 문제 : Moo 게임
// https://www.acmicpc.net/problem/5904
// 알고리즘 분류 : 분할 정복, 재귀

#include <stdio.h>

int arr[28] = { 3, };

void moo(int n, int count)
{
    if (n <= 3)
    {
        if (n == 1) putchar('m');
        else putchar('o');
        return;
    }

    int ord = arr[count] - arr[count - 1];
    if (n <= arr[count - 1]) moo(n, count - 1); // Head range
    else if (n <= ord) // Mid range
    {
        if (n == arr[count - 1] + 1) putchar('m');
        else putchar('o');
        return;
    }
    else moo(n - ord, count - 1); // Tail range; It's same pattern to the front.
}

int main(void)
{
    int n, count = 0;

    scanf("%d", &n);
    while (arr[count] < n) // Get range of Moo sequence
    {
        arr[count + 1] = arr[count] * 2 + 3 + count + 1;
        count++;
    }
    moo(n, count);
    putchar('\n');

    return 0;
}