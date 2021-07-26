// 백준 17608번 문제 : 막대기
// https://www.acmicpc.net/problem/17608
// 알고리즘 분류 : 구현, 자료 구조, 스택

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    int n, temp, count = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        stk.push(temp);
    }
    temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp < stk.top())
            count++;
        stk.pop();
    }
    cout << count << '\n';
    return 0;
}