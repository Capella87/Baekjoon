// 백준 5525번 문제 : IOIOI
// https://www.acmicpc.net/problem/5525
// 알고리즘 분류 : 문자열

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_satisfied_ioi(char* arr, size_t len, size_t cur, int n, size_t* p)
{
    int satisfied = 0;
    bool left_nest = false;
    bool center_o = false;
    for (*p = cur; *p < len;)
    {
        switch (arr[*p])
        {
        case 'O':
            if (left_nest && !center_o)
            {
                center_o = true;
            }
            else goto evaluate;
            (*p)++;
            break;
        case 'I':
            if (!left_nest)
            {
                left_nest = true;
                (*p)++;
            }
            else if (center_o)
            {
                left_nest = false;
                center_o = false;
                satisfied++;
            }
            else goto evaluate;
            break;
        }
    }
    evaluate:
    return (satisfied < n) ? 0 : (satisfied - n + 1);
}

int get_ioi(char* arr, size_t len, int n)
{
    size_t last_loc = 0;
    int count = 0;
    for (size_t i = 0; i < len;)
    {
        if (arr[i] != 'I')
        {
            i++;
            continue;
        }
        count += count_satisfied_ioi(arr, len, i, n, &last_loc);
        i = last_loc;
    }
    return count;
}

int main(void)
{
    int n, m;
    char* arr = NULL;

    scanf("%d %d", &n, &m);
    getchar();
    arr = (char*)malloc((m + 1) * sizeof(char));
    scanf("%s", arr);
    printf("%d\n", get_ioi(arr, m, n));

    free(arr);
    return 0;
}
