// 백준 1316번 문제 : 그룹 단어 체커
// https://www.acmicpc.net/problem/1316
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int checkGroup(char*, bool*);

int main(void)
{
    int it;
    int group = 0;
    char input[101] = "";

    scanf("%d", &it);
    getchar();
    for (int i = 0; i < it; i++)
    {
        scanf("%[^\n]", input);
        getchar();
        bool alpInfo[26] = { false, };
        group += checkGroup(input, alpInfo);
    }
    printf("%d\n", group);

    return 0;
}

int checkGroup(char* target, bool* alphabetInfo)
{
    char* pos = target;
    char ch = *pos;
    size_t len = strlen(target);

    if (len < 2)
        return 1;

    for (; pos < target + len; pos++)
    {
        if (alphabetInfo[*pos - 'a'] == false)
        {
            ch = *pos;
            alphabetInfo[*pos - 'a'] = true;
        }
        else if (ch == *pos) continue;
        else return 0;
    }

    return 1;
}
