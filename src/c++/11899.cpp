// 백준 11899번 문제 : 괄호 끼워넣기
// https://www.acmicpc.net/problem/11899
// 알고리즘 분류 : 자료 구조, 문자열, 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stack <char>bracket;
    string input;

    getline(cin, input);
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (!bracket.empty() && bracket.top() == '(' && input[i] == ')')
            bracket.pop();
        else bracket.push(input[i]);
    }
    cout << bracket.size() << '\n';
    return 0;
}