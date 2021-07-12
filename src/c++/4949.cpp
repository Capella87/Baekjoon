// 백준 4949번 문제 : 균형잡힌 세상
// https://www.acmicpc.net/problem/4949
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stack<char> stk;
    string input;
    bool isBalanced;

    while (1)
    {
        isBalanced = true;
        getline(cin, input);
        if (input == ".") break;

        for (size_t i = 0; input[i] != '.'; i++)
        {
            if (input[i] == '(' || input[i] == '[')
                stk.push(input[i]);
            else if ((input[i] == ')' || input[i] == ']') && stk.empty())
            {
                isBalanced = false;
                break;
            }
            else if (input[i] == ')' && stk.top() == '(')
                stk.pop();
            else if (input[i] == ')' && stk.top() != '(' || input[i] == ']' && stk.top() != '[')
            {
                isBalanced = false;
                break;
            }
            else if (input[i] == ']' && stk.top() == '[')
                stk.pop();
        }
        if (stk.size() || !isBalanced) cout << "no\n";
        else cout << "yes\n";
        while (!stk.empty()) stk.pop();
    }

    return 0;
}