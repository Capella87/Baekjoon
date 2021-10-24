// 백준 10798번 문제 : 세로읽기
// https://www.acmicpc.net/problem/10798
// 알고리즘 분류 : 구현, 문자열

#include <iostream>
#include <string>
#define STR 5
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string arr[STR];
    size_t lenArr[STR];
    size_t* max = lenArr;

    for (int i = 0; i < STR; i++)
    {
        getline(cin, arr[i]);
        lenArr[i] = arr[i].length();
        if (lenArr[i] > *max) max = lenArr + i;
    }
    for (size_t i = 0; i < *max; i++)
    {
        for (size_t j = 0; j < STR; j++)
        {
            if (lenArr[j] <= i) continue;
            cout << arr[j][i];
        }
    }
    cout << '\n';
    return 0;
}