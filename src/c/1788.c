// 백준 1788번 문제 : 피보나치 수의 확장
// https://www.acmicpc.net/problem/1788
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍

#include <stdio.h>
#include <math.h>

void print_result(long long target)
{
    long long a = target;
    short is_plus = 1;
    if (target < 0)
    {
        a *= -1;
        is_plus = -1;
    }

    printf("%d\n%lld\n", is_plus, a);
}

int main(void)
{
    int n;

    scanf("%d", &n);
    int ab = abs(n);
    
    if (ab <= 1)
    {
        printf("%d\n%d\n", ab, ab);
        return 0;
    }

    long long result = 0, n1 = 1, n2 = 0;
    for (int i = 2; i <= ab; i++)
    {
        result = ((n2 % 1000000000) + (n1 % 1000000000)) % 1000000000;
        n2 = n1;
        n1 = result;
    }
    if ((n < 0) && (ab % 2 == 0)) result *= -1;
    print_result(result);
    return 0;
}
