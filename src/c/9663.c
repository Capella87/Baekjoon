// 백준 9663번 문제 : N-Queen
// https://www.acmicpc.net/problem/9663
// 알고리즘 분류 : 브루트포스 알고리즘, 백트래킹

#include <stdio.h>
#include <stdbool.h>

int n = 0;
bool is_used_column[40];
bool is_used_right_up[40];
bool is_used_right_down[40];
int result = 0;

void n_queen(int cur)
{
    if (cur == n)
    {
        result++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // Yes. It is an impossible case
        if (is_used_column[i] || is_used_right_up[i + cur] ||
            is_used_right_down[n - 1 + i - cur]) continue;
        is_used_column[i] = true;
        is_used_right_up[i + cur] = true;
        is_used_right_down[n - 1 + i - cur] = true;

        // Go to the next row
        n_queen(cur + 1);

        // Flag state to false
        is_used_right_down[n - 1 + i - cur] = false;
        is_used_right_up[i + cur] = false;
        is_used_column[i] = false;
    }
}

int main(void)
{
    scanf("%d", &n);

    n_queen(0);
    printf("%d\n", result);

    return 0;
}
