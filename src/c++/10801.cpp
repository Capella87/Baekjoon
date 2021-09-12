// 백준 10801번 문제 : 카드게임
// https://www.acmicpc.net/problem/10801
// 알고리즘 분류 : 구현

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a[10], b[10];
    int awin = 0, bwin = 0;
    
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        cin >> b[i];
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > b[i])
            awin++;
        else if (a[i] < b[i])
            bwin++;
    }
    if (awin > bwin) cout << "A\n";
    else if (awin < bwin) cout << "B\n";
    else cout << "D\n";
    return 0;
}