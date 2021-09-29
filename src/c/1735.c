// 백준 1735번 문제 : 분수 합
// https://www.acmicpc.net/problem/1735
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>
typedef long long int64;

int64 getGCD(int64 a, int64 b)
{
    return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void)
{
    int64 a, ad, b, bd;
    int64 temp, r, rd;

    scanf("%lld %lld", &a, &ad);
    scanf("%lld %lld", &b, &bd);
    temp = getGCD(ad, a);
    a /= temp;
    ad /= temp;
    temp = getGCD(bd, b);
    b /= temp;
    bd /= temp;

    if (ad != bd)
    {
        rd = (ad * bd) / ((ad > bd) ? getGCD(ad, bd) : getGCD(bd, ad));
        r = a * (rd / ad) + b * (rd / bd);
    }
    else
    {
        r = a + b;
        rd = ad;
    }
    temp = getGCD(r, rd);
    r /= temp;
    rd /= temp;
    printf("%lld %lld\n", r, rd);
    return 0;
}