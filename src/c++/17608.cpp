// 백준 11655번 문제 : ROT13
// https://www.acmicpc.net/problem/11655
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stack<int> bar;
    int n, input;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (bar.empty() || !bar.empty() && bar.top() < input)
            bar.push(input);
    }
    cout << bar.size() << '\n';
    return 0;
}