// 백준 17413번 문제 : 단어 뒤집기 2
// https://www.acmicpc.net/problem/17413
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string input;

    getline(cin, input);
    size_t len = input.length();

    string part = "";
    bool is_special = false;
    for (size_t i = 0; i < len; i++)
    {
        while (input[i] != ' ' && input[i] != '<' && !is_special && i < len)
            part += input[i++];
        if (input[i] == '<' || input[i] == ' ' || input[i] == '\0')
        {
            if (!part.empty())
            {
                int part_len = (int)part.length();
                for (int j = part_len - 1; j >= 0; j--)
                    cout << part[j];
                part.clear();
            }
            if (input[i] == '<') is_special = true;
            if (input[i]) cout << input[i];
            continue;
        }
        else if (input[i] == '>')
            is_special = false;
        cout << input[i];
    }

    return 0;
}