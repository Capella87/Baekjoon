// 백준 2877번 문제 : 4와 7
// https://www.acmicpc.net/problem/2877
// 알고리즘 분류 : 수학, 구현

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k, near = 1, digit = 0;
    string result = "";

    cin >> k;
    k++;
    while (near <= k) // Get digit of the number.
    {
        near *= 2;
        digit++;
    }
    near /= 2;
    digit--;
    k -= near;

    for (int i = 0; i < digit; i++) // Initialization
        result += '4';

    int j = 0;
    while (k) // Conversion; Like binary number conversion.
    {
        int m = k % 2;
        if (m) result[j] = '7';
        j++;
        k /= 2;
    }

    for (int i = int(result.length()) - 1; i >= 0; i--) // Output is reversed.
        cout << result[i];
    cout << '\n';

    return 0;
}