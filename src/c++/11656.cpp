// 백준 11656번 문제 : 접미사 배열
// https://www.acmicpc.net/problem/11656
// 알고리즘 분류 : 문자열, 정렬

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str[1001];
    string input;

    cin >> input;
    size_t len = input.size();
    for (int i = 0; i < len; i++)
        str[i] = input.substr(i);
    sort(str, str + len);
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    return 0;
}