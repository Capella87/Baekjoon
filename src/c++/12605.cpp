// 백준 12605번 문제 : 단어순서 뒤집기
// https://www.acmicpc.net/problem/12605
// 알고리즘 분류 : 구현, 자료 구조, 문자열, 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack <string>stk;
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        string input;
        string temp = "";
        getline(cin, input);
        size_t len = input.length();
        for (size_t j = 0; j <= len; j++)
        {
            if (input[j] == '\0' || input[j] == ' ')
            {
                stk.push(temp);
                temp = "";
            }
            else temp += input[j];
        }
        cout << "Case #" << i + 1 << ':';
        while (!stk.empty())
        {
            cout << ' ';
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }
    return 0;
}