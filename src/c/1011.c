// 백준 1011번 문제 : Fly me to the Alpha Centauri
// https://www.acmicpc.net/problem/1011
// 알고리즘 분류 : 수학

#include <stdio.h>
#include <math.h>
// This problem requires long long to prevent overflow problem
long long getCount(const long long x, const long long y)
{
    long long diff = y - x, seed;

    seed = (long long)sqrt((double)diff); // 제곱시 diff보다 작거나 같은 수를 얻는다. (최고 속도)
    diff -= (seed * seed);  
    // diff가 어떤 수의 제곱이 될 때 기본적인 워프 횟수는 2 * n - 1회이다;
    // 기본적으로 제곱이 되는 경우 diff = 16일때 이동 거리는 1 2 3 4 3 2 1의 대칭성을 보인다.
    // diff가 루트가 정수가 되는 수 사이인 경우 이 대칭성에 최대 속도 아래로 몇 번 더 이동할 것이다.
    return seed * 2 - 1 + (long long)ceil((double)diff / (double)seed);
}

int main(void)
{
    int t;
    long long x, y;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &x, &y);
        printf("%lld\n", getCount(x, y));
    }

    return 0;
}