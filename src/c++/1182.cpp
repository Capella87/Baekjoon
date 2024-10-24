// 백준 1182번 문제 : 부분수열의 합
// https://www.acmicpc.net/problem/1182
// 알고리즘 분류 : 브루트포스 알고리즘, 백트래킹

#include <iostream>
using namespace std;

int n, s;
int* arr = NULL;

int GetPartialSequenceSum(int idx, int sum)
{
    if (idx == n) return 0;

    int rt = 0;

    rt += GetPartialSequenceSum(idx + 1, sum);
    rt += ((sum + arr[idx] == s) ? 1 : 0) + GetPartialSequenceSum(idx + 1, sum + arr[idx]);

    return rt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << GetPartialSequenceSum(0, 0) << '\n';

    delete[] arr;
    return 0;
}
