// 백준 1074번 문제 : Z
// https://www.acmicpc.net/problem/1074
// 알고리즘 분류 : 분할 정복, 재귀

#include <stdio.h>

int get_pow(int base, int exponent) // 그냥 Pow로 해도 메모리가 더 나갈 뿐 지연은 없었으므로 필요 없음
{
    if (!base || !exponent) return 1;
    else if (exponent % 2 == 1) return base * get_pow(base, exponent - 1);
    else
    {
        int temp = get_pow(base, exponent / 2);
        return temp * temp;
    }
}

int visit_order(int min, int max, int length, int row, int column)
{
    if (length == 2)
    {
        int ost = row * 2 + column;
        return min + ost;
    }
    else
    {
        int diff = max - min;
        int n_len = length / 2;
        
        int offset = 2 * (row / n_len) + column / n_len;
        min += (diff + 1) / 4 * offset;
        return visit_order(min, diff / 4 + min, n_len, row % n_len, column % n_len);
    }
}

int main(void)
{
    int n, r, c;

    scanf("%d %d %d", &n, &r, &c);
    int length = get_pow(2, n);
    int max = length * length;
    printf("%d\n", visit_order(0, max - 1, length, r, c));
    return 0;
}
