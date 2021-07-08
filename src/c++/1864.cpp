// 백준 1864번 문제 : 문어 숫자
// https://www.acmicpc.net/problem/1864
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <string>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;

    while (1)
    {
        getline(cin, input);
        if (input == "#") break;
        int result = 0;
        for (string::iterator i = input.begin(); i != input.end(); i++)
        {
            result *= 8;
            switch (*i)
            {
            case '\\':
                result += 1;
                break;
            case '(':
                result += 2;
                break;
            case '@':
                result += 3;
                break;
            case '?':
                result += 4;
                break;
            case '>':
                result += 5;
                break;
            case '&':
                result += 6;
                break;
            case '%':
                result += 7;
                break;
            case '/':
                result -= 1;
                break;
            }
        }
        cout << result << '\n';
    }

    return 0;
}