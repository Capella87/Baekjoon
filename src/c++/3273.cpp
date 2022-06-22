// 백준 3273번 문제 : 두 수의 합
// https://www.acmicpc.net/problem/3273
// 알고리즘 분류 : 정렬, 두 포인터

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, subtotal = 0, count = 0, temp;
    vector<int> arr;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    cin >> x;

    int left = 0, right = n - 1;
    while (1)
    {
        if (left >= right) break;
        subtotal = arr[left] + arr[right];
        if (subtotal > x) right--;
        else if (subtotal < x) left++;
        else
        {
            left++;
            right--;
            count++;
        }
    }
    cout << count << '\n';
    
    return 0;
}