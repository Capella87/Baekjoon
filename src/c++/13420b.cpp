// 백준 13420번 문제 : 사칙연산
// https://www.acmicpc.net/problem/13420
// 알고리즘 분류 : 수학, 문자열, 사칙연산

// Simply solved problem by scanf

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    long long a, b, c, result;
    char op, eq;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %c %lld %c %lld", &a, &op, &b, &eq, &c);
        switch (op)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        }

        if (result == c) puts("correct");
        else puts("wrong answer");
    }

    return 0;
}