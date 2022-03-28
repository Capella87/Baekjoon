// 백준 10816번 문제 : 숫자 카드 2
// https://www.acmicpc.net/problem/10816
// 알고리즘 분류 : 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵

// Using counting sort

#include <iostream>
using namespace std;

int plusArr[10000001]{ 0, };
int minusArr[10000000]{ 0 };

void countingSort(int* arr, const int size)
{
    for (auto i = 0; i < size; i++)
    {
        if (arr[i] >= 0) plusArr[arr[i]]++;
        else minusArr[(arr[i] + 1) * (-1)]++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;

    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    countingSort(arr, n);
    cin >> m;
    int* input = new int[m];
    for (auto i = 0; i < m; i++)
        cin >> input[i];
    for (auto i = 0; i < m; i++)
    {
        if (input[i] >= 0) cout << plusArr[input[i]] << ' ';
        else cout << minusArr[(input[i] + 1) * (-1)] << ' ';
    }
    
    delete[] arr;
    delete[] input;
    return 0;
}