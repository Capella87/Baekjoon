// 백준 17298번 문제 : 오큰수
// https://www.acmicpc.net/problem/17298
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stack<int> index;
    int n;

    cin >> n;
    int* arr = new int[n];
    int* result = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        while (!index.empty() && arr[index.top()] < arr[i])
        {
            result[index.top()] = arr[i];
            index.pop();
        }
        index.push(i);
    }
    while (!index.empty())
    {
        result[index.top()] = -1;
        index.pop();
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << '\n';

    delete[] arr;
    delete[] result;
    return 0;
}