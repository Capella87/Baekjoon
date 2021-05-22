// 백준 2576번 문제 : 홀수
// https://www.acmicpc.net/problem/2576
// 알고리즘 분류 : 수학, 구현

#include <iostream>
using namespace std;

int main()
{
    int num[7];
    int total = 0, min = -1;

    for (int i = 0; i < 7; i++)
    {
        cin >> num[i];
        if (num[i] % 2 == 1) // 홀수인 경우
        {
            total += num[i];
            if (min > num[i] || min == -1) min = num[i];
        }
    }
    if (min == -1) printf("%d\n", min); // 홀수가 없는 경우 -1가 있을 min만 출력
    else printf("%d\n%d\n", total, min);

    return 0;
}