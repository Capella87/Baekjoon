// 백준 17299번 문제 : 오등큰수
// https://www.acmicpc.net/problem/17299
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
using namespace std;
const int MAX = 1000000;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack <int> stk;
    int* arrCount = new int[MAX]();
    int n;

    cin >> n;
    int* arr = new int[n];
    int* result = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arrCount[arr[i] - 1]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int numIdx = arr[i] - 1;
        while (!stk.empty() && arrCount[numIdx] >= arrCount[stk.top() - 1])
            stk.pop();
        result[i] = stk.empty() ? -1 : stk.top();
        stk.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';

    delete[] arrCount;
    delete[] result;
    delete[] arr;
    return 0;
}