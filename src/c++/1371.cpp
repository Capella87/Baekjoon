// 백준 1371번 문제 : 가장 많은 글자
// https://www.acmicpc.net/problem/1371
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <cstdio>
#include <string>
#include <iterator>

using namespace std;

int alphabet[26]{ 0, };

void findMax(void)
{
    int* pos = alphabet, * max = pos;

    for (; pos < alphabet + 26; pos++)
        if (*pos > *max) max = pos;
    for (pos = max; pos < alphabet + 26; pos++)
        if (*pos == *max)
            printf("%c", 'a' + int(pos - alphabet));
    putchar('\n');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string input;
    string::iterator pos;

    // Procedure will not escape from the loop until EOF input (^Z in Windows or ^D in Linux) or abort signal (^C).
    while (cin >> input)
    {
        for (pos = input.begin(); pos != input.end(); pos++)
            if (*pos >= 'a' && *pos <= 'z')
                alphabet[*pos - 'a']++;
        input.clear();
    }
    findMax();

    return 0;
}