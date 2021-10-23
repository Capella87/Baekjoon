// 백준 1120번 문제 : 문자열
// https://www.acmicpc.net/problem/1120
// 알고리즘 분류 : 구현, 문자열, 브루트포스 알고리즘

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    auto t = b.length() - a.length();
    auto a_len = a.length();
    int diff = 0, min = 1000;
    for (auto i = 0; i <= t; i++)
    {
        diff = 0;
        for (auto j = 0; j < a_len; j++)
            if (a[j] != b[i + j]) diff++;
        if (min >= diff) min = diff;
    }
    cout << min << '\n';
    return 0;
}