// 백준 14954번 문제 : Happy Number
// https://www.acmicpc.net/problem/14954
// 알고리즘 분류 : 수학, 구현, 사칙연산, 시뮬레이션

#include <iostream>
#include <vector>
using namespace std;

bool isHappyNumber(int n)
{
    const int init = n;
    vector<int> v;

    do
    {
        if (n == 1) return true;
        int temp = n, num = 0;
        while (temp != 0)
        {
            int t = temp % 10;
            num += t * t;
            temp /= 10;
        }
        int size = int(v.size());
        for (int i = 0; i < size; i++)
            if (v[i] == num) return false;
        v.push_back(num);
        n = num;
    } while (n != init);
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    scanf("%d", &n);
    puts(isHappyNumber(n) ? "HAPPY" : "UNHAPPY");
    return 0;
}