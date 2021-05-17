// 백준 9625번 문제 : BABBA
// https://www.acmicpc.net/problem/9625
// 알고리즘 분류 : 다이나믹 프로그래밍, 구현

#include <iostream>
using namespace std;

void getAB(const int& k)
{
    int a = 0, b = 0;
    int an1, an2, bn1, bn2;

    if (k == 1) b++;
    else if (k == 2)
    {
        a = 1;
        b = 1;
    }
    else
    {
        an1 = bn1 = bn2 = 1;
        an2 = 0;
        for (int i = 0; i < k - 2; i++)
        {
            a = an1 + an2;
            b = bn1 + bn2;
            an2 = an1;
            bn2 = bn1;
            an1 = a;
            bn1 = b;
        }
    }

    cout << a << " " << b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    getAB(k);

    return 0;
}