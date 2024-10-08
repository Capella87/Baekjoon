// 백준 6603번 문제 : 로또
// https://www.acmicpc.net/problem/6603
// 알고리즘 분류 : 수학, 조합론, 백트래킹, 재귀

#include <stdio.h>

void print(int* nums)
{
    for (int i = 0; i < 6; i++) printf("%d ", nums[i]);
    putchar('\n');
}

void search(int k, int current, int last_n_idx, int* nums, int* selections)
{
    if (current == 6)
    {
        print(selections);
        return;
    }
    for (int i = last_n_idx + 1; i < k && ((6 - current) <= (k - i)); i++)
    {
        selections[current] = nums[i];
        search(k, current + 1, i, nums, selections);
    }
}

void solve(int k, int* nums)
{
    int selections[13] = { 0, };
    search(k, 0, -1, nums, selections);
}

int main(void)
{
    int k;
    int numbers[13];

    while (1)
    {
        scanf("%d", &k);
        if (k == 0) break;

        for (int i = 0; i < k; i++) scanf("%d", &numbers[i]);
        solve(k, numbers);
        putchar('\n');
    }
    return 0;
}
