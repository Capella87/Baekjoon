// 백준 2885번 문제 : 초콜릿 식사
// https://www.acmicpc.net/problem/2885
// 알고리즘 분류 : 수학, 그리디 알고리즘, 정수론

#include <iostream>
#include <string>
using namespace std;

int k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    int i = 1;
    while (i < k)
    {
        i *= 2;
    }
    int size = i;
    int decomposed = k;
    int c = 0;

    while (size > 1 && decomposed > 0)
    {
        if (size <= decomposed)
        {
            decomposed -= size;
        }

        if (!decomposed)
        {
            break;
        }
        size /= 2;
        c++;
    }
    cout << i << " " << c;
    return 0;
}
