// 백준 1874번 문제 : 스택 수열
// https://www.acmicpc.net/problem/1874
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    int* seq = new int[n];
    stack <int>numStk;
    queue <char>seqHistory;

    for (int i = 0; i < n; i++)
        cin >> seq[i];
    int recentNumPush = 0;
    for (int i = 0; i < n; i++)
    {
        while (recentNumPush < seq[i])
        {
            numStk.push(++recentNumPush);
            seqHistory.push('+');
        }
        if (numStk.top() == seq[i])
        {
            numStk.pop();
            seqHistory.push('-');
        }
        else break;
    }
    
    if (!numStk.empty()) cout << "NO\n";
    else
    {
        while (!seqHistory.empty())
        {
            cout << seqHistory.front() << '\n';
            seqHistory.pop();
        }
    }
    delete[] seq;
    return 0;
}