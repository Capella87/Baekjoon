// 백준 2847번 문제 : 게임을 만든 동준이
// https://www.acmicpc.net/problem/2847
// 알고리즘 분류 : 그리디 알고리즘

#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;
int* arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        if (arr[j] >= arr[j + 1])
        {
            int c = arr[j] - arr[j + 1] + 1;
            cnt += c;
            arr[j] -= c;
            continue;
        }
    }
    cout << cnt << '\n';
    return 0;
}
