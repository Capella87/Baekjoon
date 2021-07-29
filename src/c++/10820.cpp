// 백준 10820번 문제 : 문자열 분석
// https://www.acmicpc.net/problem/10820
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string input;

    while (1)
    {
        int smallCount = 0, bigCount = 0, numCount = 0, spaceCount = 0;
        getline(cin, input);
        if (input == "") break;
        size_t len = input.length();
        for (int i = 0; i < len; i++)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
                smallCount++;
            else if (input[i] >= 'A' && input[i] <= 'Z')
                bigCount++;
            else if (input[i] >= '0' && input[i] <= '9')
                numCount++;
            else if (input[i] == ' ')
                spaceCount++;
        }
        cout << smallCount << ' ' << bigCount << ' ';
        cout << numCount << ' ' << spaceCount << '\n';
    }

    return 0;
}