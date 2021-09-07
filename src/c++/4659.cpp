// 백준 4659번 문제 : 비밀번호 발음하기
// https://www.acmicpc.net/problem/4659
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;
const string VOWELS = "aiueo";

bool checkQuality(string& target)
{
    size_t len = target.length();
    int catConsonentCount = 0, catVowelCount = 0;
    bool hasVowel = false;
    char prevChar = target[0];

    for (size_t i = 0; i < len; i++)
    {
        if (VOWELS.find(target[i]) != string::npos) // 모음
        {
            if (!hasVowel) hasVowel = true;
            catVowelCount++;
            catConsonentCount = 0;
        }
        else // 자음
        {
            catConsonentCount++;
            catVowelCount = 0;
        }
        if (catConsonentCount == 3 || catVowelCount == 3)
            goto falseExit;
        if (i && prevChar == target[i] && (target[i] != 'e' && target[i] != 'o'))
            goto falseExit;
        prevChar = target[i];
    }

    if (!hasVowel) goto falseExit;
    return true;
falseExit:
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string password;

    while (1)
    {
        getline(cin, password);
        if (password == "end") break;
        cout << '<' << password << "> is ";
        cout << ((checkQuality(password)) ? "acceptable.\n" : "not acceptable.\n");
    }
    return 0;
}