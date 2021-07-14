// 백준 11655번 문제 : 11655
// https://www.acmicpc.net/problem/11655
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    string out = "";

    getline(cin, input);
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            out += 'a' + char((int(input[i]) - 'a' + 13) % 26);
        else if (input[i] >= 'A' && input[i] <= 'Z')
            out += 'A' + char((int(input[i]) - 'A' + 13) % 26);
        else out += input[i];
    }
    cout << out << '\n';
    return 0;
}