// 백준 1159번 문제 : 농구 경기
// https://www.acmicpc.net/problem/1159
// 알고리즘 분류 : 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    bool isPossible = false;

    cin >> n;
    cin.get();
    string* str = new string[n];
    int firstLetterCount[26]{ 0, };

    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
        firstLetterCount[str[i][0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (firstLetterCount[i] >= 5)
        {
            cout << char(i + 'a');
            isPossible = true;
        }
    }
    if (!isPossible) cout << "PREDAJA";
    cout << '\n';

    delete[] str;
    return 0;
}