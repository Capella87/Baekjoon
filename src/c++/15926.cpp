// 백준 15926번 문제 : 현욱은 괄호왕이야!!
// https://www.acmicpc.net/problem/15926
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack<int> brackets;
    stack<pair<int, int>> saved;
    int n, max = 0;
    string input;

    cin >> n;
    cin.get();
    getline(cin, input);
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '(') brackets.push(i);
        else
        {
            if (!brackets.empty())
            {
                int count = 2;
                int start_idx = brackets.top();
                brackets.pop();
                while (!saved.empty() && (saved.top().second + 1 == i || saved.top().second + 1 == start_idx))
                {
                    count += saved.top().first;
                    saved.pop();
                }
                if (max < count) max = count;
                saved.push({ count, i });
            }
        }
    }
    cout << max << '\n';

    return 0;
}