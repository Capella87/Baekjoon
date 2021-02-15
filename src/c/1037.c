// 백준 1037번 문제 : 약수
// https://www.acmicpc.net/problem/1037
// 알고리즘 분류 : 수학, 정수론

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long n;
    int count, i, j, temp;
    int* arr = NULL;

    scanf("%d", &count);
    getchar();
    arr = (int*)malloc(sizeof(int) * count);
    if (arr == NULL) exit(EXIT_FAILURE);
    for (i = 0; i < count; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) // Arrangement
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    n = (long long)arr[0] * (long long) arr[count - 1]; // Multiply the first element and the last element
    printf("%lld\n", n);

    free(arr);
    return 0;
}