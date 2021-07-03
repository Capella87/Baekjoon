// 백준 15726번 문제 : 이칙연산
// https://www.acmicpc.net/problem/15726
// 알고리즘 분류 : 수학, 사칙연산

#include <iostream>
using namespace std;

int main(void)
{
    double a, b, c; // To reduce error
    cin >> a >> b >> c;
    long long result = (a * b / c) > (a / b * c) ? (long long)(a * b / c) : (long long)(a / b * c); // To save bigger number
    cout << result << '\n';
    return 0;
}