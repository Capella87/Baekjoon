// 백준 1427번 문제 : 소트인사이드
// https://www.acmicpc.net/problem/1427
// 알고리즘 분류 : 문자열, 정렬

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string input;

    cin >> input;
    int len = int(input.length());
    for (int i = 1; i < len; i++) // insertion sort
    {
        char key = input[i];
        int j = i - 1;
        while (j >= 0 && key > input[j])
        {
            input[j + 1] = input[j];
            j--;
        }
        if (i != j) input[j + 1] = key;
    }
    cout << input << '\n';
    return 0;
}