// 백준 12865번 문제 : 평범한 배낭
// https://www.acmicpc.net/problem/12865
// 알고리즘 분류 : 다이나믹 프로그래밍, 배낭 문제

// 0-1 Knapsack problem

#include <iostream>
#define LEN 100
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int n, k;
int weight[LEN];
int value[LEN];
int cache[100001]{ 0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    for (int i = 1; i <= LEN; i++)
        for (int w = k; w >= 0; w--)
            if (weight[i - 1] <= w)
                cache[w] = MAX(cache[w], cache[w - weight[i - 1]] + value[i - 1]);
    cout << cache[k] << '\n';

    return 0;
}