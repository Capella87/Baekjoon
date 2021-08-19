// 백준 14170번 문제 : 고장난 시계
// https://www.acmicpc.net/problem/14170
// 알고리즘 분류 : 수학, 구현

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    double minAngle, hourAngle;

    cin >> hourAngle >> minAngle;
    while (hourAngle >= 30)
        hourAngle -= 30;
    cout << ((0.5 * (minAngle / 6) == hourAngle) ? 'O' : 'X') << '\n';
    return 0;
}