// 백준 2475번 문제 : 검증수
// https://www.acmicpc.net/problem/2475
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <iostream>

using namespace std;

int square(int);

int main(void)
{
    int number[5];

    cin >> number[0] >> number[1] >> number[2] >> number[3] >> number[4];
    cin.get();

    cout << (square(number[0]) + square(number[1]) + square(number[2]) + square(number[3]) + square(number[4])) % 10 << endl;

    return 0;
}

int square(int input)
{
    return input * input;
}