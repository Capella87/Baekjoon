// 백준 2608번 문제 : 로마 숫자
// https://www.acmicpc.net/problem/2608
// 알고리즘 분류 : 수학, 구현, 문자열

#include <iostream>
#include <string>
using namespace std;
const string numOrder = "IVXLCDM";

int calcRome(const char t)
{
    int result = 0;

    if (t == 'M') result = 1000;
    else if (t == 'D') result = 500;
    else if (t == 'C') result = 100;
    else if (t == 'L') result = 50;
    else if (t == 'X') result = 10;
    else if (t == 'V') result = 5;
    else if (t == 'I') result = 1;
    return result;
}

int convertToInt(string& t)
{
    int result = 0;
    int len = int(t.length());
    for (int i = 0; i < len; i++)
    {
        int temp = calcRome(t[i]);
        if (i < len - 1)
        {
            int front = int(numOrder.find(t[i]));
            int back = int(numOrder.find(t[i + 1]));
            if (front < back)
            {
                temp = calcRome(t[i + 1]) - calcRome(t[i]);
                i++;
            }
        }
        result += temp;
    }
    return result;
}

string convertToRome(int t)
{
    string result = "";
    int divisor = 1000;

    if (t / 1000)
    {
        int i = t / 1000;
        for (int j = 0; j < i; j++)
            result += 'M';
        t %= 1000;
    }
    if (t / 100)
    {
        int i = t / 100;
        if (i == 9) result += "CM";
        else if (i >= 5 && i <= 8)
        {
            result += "D";
            for (int j = 5; j < i; j++)
                result += "C";
        }
        else if (i == 4) result += "CD";
        else
            for (int j = 0; j < i; j++)
                result += "C";
        t %= 100;
    }
    if (t / 10)
    {
        int i = t / 10;
        if (i == 9) result += "XC";
        else if (i >= 5 && i <= 8)
        {
            result += "L";
            for (int j = 5; j < i; j++)
                result += "X";
        }
        else if (i == 4) result += "XL";
        else
            for (int j = 0; j < i; j++)
                result += "X";
        t %= 10;
    }
    if (t % 10)
    {
        int i = t % 10;
        if (i == 9) result += "IX";
        else if (i >= 5 && i <= 8)
        {
            result += "V";
            for (int j = 5; j < i; j++)
                result += "I";
        }
        else if (i == 4) result += "IV";
        else
            for (int j = 0; j < i; j++)
                result += "I";
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b;

    getline(cin, a);
    getline(cin, b);
    int res = convertToInt(a) + convertToInt(b);
    cout << res << '\n';
    cout << convertToRome(res) << '\n';
    return 0;
}