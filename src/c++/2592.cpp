// 백준 2592번 문제 : 대표값
// https://www.acmicpc.net/problem/2592
// 알고리즘 분류 : 수학

#include <iostream>
#define T 10
using namespace std;

int main()
{
    int stat[T][2]{ 0, }; // 값 빈도를 저장하기 위한 배열
    int temp, i, j, total = 0, (*pos)[2] = stat;

    for (i = 0; i < T; i++)
    {
        cin >> temp;
        for (j = 0; j <= i; j++)
        {
            if (stat[j][0] == temp)
            {
                stat[j][1]++;
                break;
            }
        }
        if (j - 1 == i) // 끝까지 안 나온 경우
        {
            stat[j - 1][0] = temp;
            stat[j - 1][1]++;
        }
        total += temp;
    }
    printf("%d\n", total / T); // 평균 출력
    for (i = 0; i < T; i++)
    {
        if (stat[i][1] > *(*pos + 1))
            pos = stat + i;
        if (!stat[i][1]) break;
    }
    printf("%d\n", **pos); // 최빈값 출력

    return 0;
}