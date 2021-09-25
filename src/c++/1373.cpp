// 백준 1373번 문제 : 2진수 8진수
// https://www.acmicpc.net/problem/1373
// 알고리즘 분류 : 수학, 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string input;
    string result = "";
    getline(cin, input);
    int len = int(input.length());
    int temp = 0;

    for (size_t i = 0; i < len; i++)
    {
        if ((i + 1) % 3 == 1) temp += int(input[len - 1 - i] - '0');
        else if ((i + 1) % 3 == 2) temp += int(input[len - 1 - i] - '0') * 2;
        else temp += int(input[len - 1 - i] - '0') * 4;
        if ((i + 1) % 3 == 0 || i == len - 1)
        {
            result += char(temp + '0');
            temp = 0;
        }
    }
    len = int(result.length());
    for (int i = len - 1; i >= 0; i--)
        cout << result[i];
    return 0;
}