// 백준 1662번 문제 : 압축
// https://www.acmicpc.net/problem/1662
// 알고리즘 분류 : 자료 구조, 스택, 재귀

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char> brackets;

int getOrigLen(string& str, int begin, int len)
{
    int sectionLen = 0;
    char prev = 0;

    for (int i = begin; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sectionLen++;
            prev = str[i];
        }
        else if (str[i] == '(')
        {
            --sectionLen;
            int pStkCount = int(brackets.size());
            brackets.push('(');
            sectionLen += int(prev - '0') * getOrigLen(str, i + 1, len);
            ++i;
            while ( brackets.size() > pStkCount && i < len)
            {
                if (str[i] == ')') brackets.pop();
                else if (str[i] == '(')
                    brackets.push('(');
                i++;
            }
            --i;
        }
        else if (str[i] == ')') break;
    }
    return sectionLen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string compressedStr;

    getline(cin, compressedStr);
    int len = int(compressedStr.length());
    cout << getOrigLen(compressedStr, 0, len) << '\n';
    return 0;
}