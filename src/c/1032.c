// 백준 1032번 문제 : 명령 프롬프트
// https://www.acmicpc.net/problem/1032
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n;
    char temp[51], *common = NULL;
    size_t len;

    scanf("%d", &n);
    getchar();

    scanf("%[^\n]", temp);
    getchar();
    len = strlen(temp);
    common = (char*)malloc(sizeof(char) * (len + 1));
    strcpy(common, temp);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%[^\n]", temp);
        getchar();
        for (size_t j = 0; j < len; j++)
            if (temp[j] != common[j])
                common[j] = '?';
    }
    puts(common);

    free(common);
    return 0;
}