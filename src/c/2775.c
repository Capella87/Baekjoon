// 백준 2775번 문제 : 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775
// 알고리즘 분류 : 수학, 조합론

#include <stdio.h>
#include <stdlib.h>

int getPopulation(int k, int n)
{
    int** apartment = (int**)malloc(sizeof(int*) * (k + 1));

    apartment[0] = (int*)malloc(sizeof(int) * n); // first floor
    for (int i = 0; i < n; i++)
        apartment[0][i] = i + 1;
    for (int i = 1; i <= k; i++) // for 2nd and more
    {
        apartment[i] = (int*)malloc(sizeof(int) * n);
        apartment[i][0] = 1;
        for (int j = 1; j < n; j++)
            apartment[i][j] = apartment[i - 1][j] + apartment[i][j - 1];
    }
    int result = apartment[k][n - 1]; // save result before deallocation
    for (int i = 0; i <= k; i++) // deallocate memory
        free(apartment[i]);
    free(apartment);
    return result;
}

int main(void)
{
    int k, n, t;

    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", getPopulation(k, n));
    }

    return 0;
}