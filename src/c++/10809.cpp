// 백준 10809번 문제 : 알파벳 찾기
// https://www.acmicpc.net/problem/10809
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main(void)
{
    string input;
    string::iterator i;
    char ch;
    int alphabet[26];

    for (int j = 0; j < 26; j++)
        alphabet[j] = -1;

    cin >> input;

    for (i = input.begin(); i != input.end(); i++)
    {
        ch = char(*i);
        if (alphabet[ch - 97] == -1)
            alphabet[ch - 97] = int(distance(input.begin(), i));
    }
    for (int j = 0; j < 26; j++)
        cout << alphabet[j] << " ";
    cout << "\n";

    return 0;
}