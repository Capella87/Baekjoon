// 백준 2386번 문제 : 도비의 영어 공부
// https://www.acmicpc.net/problem/2386
// 알고리즘 분류 : 문자열, 브루트포스 알고리즘

#include <stdio.h>
#include <string.h>

int main(void)
{
    char target;
    char input[252];
    char* pos;
    size_t len;
    int count;

    while (1)
    {
        scanf("%c", &target);
        if (target == '#') break;
        scanf("%[^\n]", input);
        getchar();
        len = strlen(input);
        for (pos = input, count = 0; pos < input + len; pos++)
            if (*pos == target || *pos == target - 32) count++;
        printf("%c %d\n", target, count);
    }

    return 0;
}
