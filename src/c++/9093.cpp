// 백준 9093번 문제 : 단어 뒤집기
// https://www.acmicpc.net/problem/9093
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string input;
    stack<char> word;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        size_t end = input.size();
        for (int j = 0; j <= end; j++)
        {
            if (input[j] == ' ' || input[j] == '\0')
            {
                while (!word.empty())
                {
                    cout << word.top();
                    word.pop();
                }
                cout << ' ';
            }
            else word.push(input[j]);
        }
        cout << '\n';
    }

    return 0;
}