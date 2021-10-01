// 백준 2436번 문제 : 공약수
// https://www.acmicpc.net/problem/2436
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>

unsigned long long gcd(unsigned long long, unsigned long long);

int main(void)
{
    unsigned long long 
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b ? gcd(b, a % b) : a;
}