// 백준 14584번 문제 : 암호 해독
// https://www.acmicpc.net/problem/14584
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    bool isFound = false;
    string encrypted;

    getline(cin, encrypted);
    cin >> n;
    int len = int(encrypted.length());
    string* arr = new string[n];
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            if (encrypted.find(arr[i]) != string::npos)
            {
                isFound = true;
                break;
            }
        }
        if (isFound) break;
        for (int i = 0; i < len; i++)
            encrypted[i] = (++encrypted[i] - 'a') % 26 + 'a';
    }
    cout << encrypted << '\n';
    delete[] arr;
    return 0;
}