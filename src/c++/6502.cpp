// 백준 6502번 문제 : 동혁 피자
// https://www.acmicpc.net/problem/6502
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <iostream>
using namespace std;

int main(void)
{
    int r, w, l, count = 0;

    while (1)
    {
        cin >> r;
        if (r == 0) break;
        cin >> w >> l;

        if ((4 * r * r) >= (w * w + l * l))
            cout << "Pizza " << ++count << " fits on the table.\n";
        else
            cout << "Pizza " << ++count << " does not fit on the table.\n";
    }

    return 0;
}

// C언어의 scanf와 printf를 사용한 경우 지연시간은 없다. (cin, cout을 사용한 여기에서는 12ms)