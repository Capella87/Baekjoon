// 백준 10214번 문제 : Baseball
// https://www.acmicpc.net/problem/10214
// 알고리즘 분류 : 수학, 구현

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, temp1, temp2;
    int k_rcrd, y_rcrd;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        k_rcrd = y_rcrd = 0;
        for (int j = 0; j < 9; j++)
        {
            cin >> temp1 >> temp2;
            y_rcrd += temp1;
            k_rcrd += temp2;
        }
        if (k_rcrd > y_rcrd) cout << "Korea\n";
        else if (k_rcrd < y_rcrd) cout << "Yonsei\n";
        else cout << "Draw\n";
    }
    return 0;
}