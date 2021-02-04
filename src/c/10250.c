// 백준 10250번 문제 : ACM 호텔
// https://www.acmicpc.net/problem/10250
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <stdio.h>

int main(void)
{
    int t, i;
    int h, w, n;
    int room;

    scanf("%d", &t);
    getchar();
    for (i = 0; i < t; i++)
    {
        scanf("%d %d %d", &h, &w, &n);
        getchar();
        room = n % h != 0 ? (n % h) * 100 + 1 + 10 / h : h * 100 + 10 / h;
        // 층(h)으로 나누어 떨어지는 경우 꼭대기층을 배정받을 것이므로 그 경우를 반영한다.
        printf("%d\n", room);
    }

    return 0;
}