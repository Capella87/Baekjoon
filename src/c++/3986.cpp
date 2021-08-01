// 백준 3986번 문제 : 좋은 단어
// https://www.acmicpc.net/problem/3986
// 알고리즘 분류 : 자료 구조, 문자열, 스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, goodCount = 0;
    string input;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        stack <char>word;
        size_t len = input.length();
        for (size_t i = 0; i < len; i++)
        {
            if (!word.empty() && word.top() == input[i])
                word.pop();
            else word.push(input[i]);
        }
        if (word.empty()) goodCount++;
    }
    cout << goodCount << '\n';
    return 0;
}