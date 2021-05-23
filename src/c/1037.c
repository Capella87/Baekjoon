// 백준 1037번 문제 : 약수
// https://www.acmicpc.net/problem/1037
// 알고리즘 분류 : 수학, 정수론

#include <stdio.h>

int main(void)
{
    // 주어지는 수에 1과 결과로 나오는 수는 없으므로 그 두개 외의 최댓값과 최솟값을 곱하면 된다.
    int max = -1, min = 1000001;
    int n, temp;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (max < temp)
            max = temp;
        if (min > temp)
            min = temp;
    }
    printf("%d\n", min * max); // 최댓값과 최솟값을 곱한 값 출력

    return 0;
}