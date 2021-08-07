// 백준 2841번 문제 : 외계인의 기타 연주
// https://www.acmicpc.net/problem/2841
// 알고리즘 분류 : 수학, 사칙연산

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int note, fret;
    int minFingerMove = 0, strNum, fretNum;
    stack<int> guitarStr[7];

    cin >> note >> fret;
    for (int i = 0; i < note; i++)
    {
        cin >> strNum >> fretNum;
        strNum--;
        while (!guitarStr[strNum].empty() && guitarStr[strNum].top() > fretNum)
        {
            guitarStr[strNum].pop();
            minFingerMove++;
        }
        if (!guitarStr[strNum].empty() && guitarStr[strNum].top() == fretNum) continue;
        guitarStr[strNum].push(fretNum);
        minFingerMove++;
    }
    cout << minFingerMove << '\n';
    return 0;
}