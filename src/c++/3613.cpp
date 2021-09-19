// 백준 3613번 문제 : Java vs C++
// https://www.acmicpc.net/problem/3613
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;

string convertToCppStyle(string& input, const size_t len)
{
    bool hasUnderbarPrev = false;
    string result = "";

    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == '_') hasUnderbarPrev = true;
        else if (hasUnderbarPrev)
        {
            result += input[i] - 32;
            hasUnderbarPrev = false;
        }
        else result += input[i];
    }
    return result;
}

string convertToJavaStyle(string& input, const size_t len)
{
    bool hasBigCasePrev = false;
    string result = "";

    for (size_t i = 0; i < len; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z') hasBigCasePrev = true;
        else if (hasBigCasePrev)
        {
            result += '_';
            result += input[i] + 32;
            hasBigCasePrev = false;
        }
        else result += input[i];
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string input;
    bool isJavaStyle = false;
    bool isCppStyle = false;

    cin >> input;
    size_t len = input.length();
    for(size_t i = 0; i < len; i++)
    {
        if (!isJavaStyle && input[i] == '_')
            isJavaStyle = true;
        if (!isCppStyle && input[i] >= 'A' && input[i] <= 'Z' && i)
            isCppStyle = true;
    }
    if (isJavaStyle && !isCppStyle)
        cout << convertToCppStyle(input, len) << '\n';
    else if (isCppStyle && !isJavaStyle)
        cout << convertToJavaStyle(input, len) << '\n';
    else cout << "Error!\n";
    return 0;
}