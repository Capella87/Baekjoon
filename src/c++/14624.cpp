// 백준 17496번 문제 : 전북대학교
// https://www.acmicpc.net/problem/14624
// 알고리즘 분류 : 구현

#include <iostream>
#include <cstdio>
using namespace std;

void getSymbol(const int&);

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "I LOVE CBNU\n";
    else getSymbol(n);

    return 0;
}

void getSymbol(const int& n)
{
    for (int i = 0; i < n; i++)
        putchar('*');
    putchar('\n');
    for (int i = 0; i < n / 2; i++)
        putchar(' ');
    puts("*");
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2 - i - 1; j++)
            putchar(' ');
        putchar('*');
        for (int j = 0; j < i * 2 + 1; j++)
            putchar(' ');
        puts("*");
    }
}