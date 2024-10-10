// 백준 16974번 문제 : PPAP
// https://www.acmicpc.net/problem/16120
// 알고리즘 분류 : 자료 구조, 문자열, 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<size_t> ppapStack;
    int ppapRequiredIdx = 0;
    bool isValid = true;
    size_t ppapIdxArr[4] = { 0, };
    string input;

    cin >> input;
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == 'P')
        {
            if (ppapRequiredIdx != 2)
            {
                ppapIdxArr[ppapRequiredIdx++] = i;
            }
            else
            {
                ppapStack.push(ppapIdxArr[0]);
                ppapIdxArr[0] = ppapIdxArr[1];
                ppapIdxArr[1] = i;
            }
            if (ppapRequiredIdx == 4)
            {
                if (!ppapStack.empty())
                {
                    ppapIdxArr[0] = ppapStack.top();
                    ppapStack.pop();
                    ppapIdxArr[1] = i;
                    ppapRequiredIdx = 2;
                }
                else
                {
                    ppapIdxArr[0] = i;
                    ppapRequiredIdx = 1;
                }
            }
        }
        else if (input[i] == 'A' && ppapRequiredIdx == 2)
        {
            ppapIdxArr[ppapRequiredIdx++] = i;
        }
        else
        {
            isValid = false;
            break;
        }
    }
    cout << (isValid && ppapRequiredIdx == 1 ? "PPAP" : "NP") << '\n';
    return 0;
}
