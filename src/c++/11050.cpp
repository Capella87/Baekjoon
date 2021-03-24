// 백준 11050번 문제 : 이항 계수 1
// https://www.acmicpc.net/problem/11050
// 알고리즘 분류 : 수학, 구현, 조합론

#include <iostream>

using namespace std;

int getCoefficient(const int, const int);
int factorial(int, int limit = -1);

int main(void)
{
    int n, k;
    
    cin >> n >> k;
    cout << getCoefficient(n, k) << endl;

    return 0;
}

int getCoefficient(const int n, const int k)
{
    return factorial(n, k) / factorial(k);
}

int factorial(int n, int limit)
{
    if (n == 0 || limit == 0)
        return 1;
    else if (limit == -1)
        return n * factorial(n - 1);
    else
        return n * factorial(n - 1, limit - 1);
}