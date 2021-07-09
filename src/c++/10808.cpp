// 백준 10808번 문제 : 알파벳 개수
// https://www.acmicpc.net/problem/10808
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    array<int, 26> abcStat{};

    cin >> input;
    size_t len = input.length();

    for (int i = 0; i < len; i++)
        abcStat[input[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << abcStat[i] << ' ';
    cout << '\n';

    return 0;
}