// 백준 17496번 문제 : 스타후르츠
// https://www.acmicpc.net/problem/17496
// 알고리즘 분류 : 수학, 사칙연산

#include <iostream>
using namespace std;

int main(void)
{
    int n, t, c, p;

    cin >> n >> t >> c >> p;
    cout << ((n - 1) / t) * c * p << '\n';
    
    return 0;
}