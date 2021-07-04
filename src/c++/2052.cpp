// 백준 2052번 문제 : 지수연산
// https://www.acmicpc.net/problem/2052
// 알고리즘 분류 : 수학, 임의 정밀도 / 큰 수 연산

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    printf("%.*lf\n", n, pow(0.5, n));
    return 0;
}