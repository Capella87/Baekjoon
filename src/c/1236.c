// 백준 1236번 문제 : 성 지키기
// https://www.acmicpc.net/problem/1276
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(void)
{
    int row, col, row_vacant = 0, col_vacant = 0;

    scanf("%d %d", &row, &col);
    getchar();
    char* castle = (char*)malloc(sizeof(char) * (col + 1));
    bool* col_people = (bool*)malloc(sizeof(bool) * col);
    bool* row_people = (bool*)malloc(sizeof(bool) * row);
    memset(col_people, false, sizeof(bool) * col);
    memset(row_people, false, sizeof(bool) * row);
    for (int i = 0; i < row; i++)
    {
        scanf("%[^\n]", castle);
        getchar();
        for (int j = 0; j < col; j++)
        {
            if (castle[j] == 'X')
            {
                row_people[i] = true;
                col_people[j] = true;
            }
        }
    }
    free(castle);
    for (int i = 0; i < row; i++) if (!row_people[i]) row_vacant++;
    for (int i = 0; i < col; i++) if (!col_people[i]) col_vacant++;
    printf("%d\n", MAX(row_vacant, col_vacant));
    free(col_people);
    free(row_people);
    return 0;
}