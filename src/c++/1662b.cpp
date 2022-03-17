// 백준 1662번 문제 : 압축
// https://www.acmicpc.net/problem/1662
// 알고리즘 분류 : 자료 구조, 스택, 재귀

// Non-recursive and simpler code

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string input;
    char prev = 0;
    int count = 0;
    stack<pair<int, int>> stk;

    getline(cin, input);
    int size = (int)input.length();
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '(')
        {
            stk.push({ (int)(prev - '0'), count - 1 });
            count = 0;
        }
        else if (input[i] == ')')
        {
            pair<int, int> temp = stk.top();
            stk.pop();
            count = temp.first * count + temp.second;
        }
        else count++;
        prev = input[i];
    }
    cout << count << '\n';

    return 0;
}