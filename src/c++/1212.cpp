// 백준 1212번 문제 : 8진수 2진수
// https://www.acmicpc.net/problem/1212
// 알고리즘 분류 : 수학, 구현, 문자열

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

string binaryOut(string&);

int main(void)
{
    string octal;

    cin >> octal;
    cout << binaryOut(octal) << endl;

    return 0;
}

string binaryOut(string& target)
{
    string::iterator i = target.begin();
    string result;
    const string bin[8]{ "0", "1", "10", "11", "100", "101", "110", "111" };
    int ch;

    ch = int(char(*i++) - '0');
    result = bin[ch];

    for (; i != target.end(); i++)
    {
        ch = int(char(*i) - '0');
        if (ch <= 1)
            result += "00";
        else if (ch > 1 && ch < 4)
            result += "0";
        result += bin[ch];
    }

    return result;
}