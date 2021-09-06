// 백준 1158번 문제 : 요세푸스 문제
// https://www.acmicpc.net/problem/1158
// 알고리즘 분류 : 자료 구조, 큐

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    deque <int> box;
    int n, k, count = 0;

    cin >> n >> k;
    int* result = new int[n];
    for (int i = 1; i <= n; i++)
        box.push_back(i);
    while (!box.empty() && count < n)
    {
        int row = 1;
        while (row != k)
        {
            box.push_back(box.front());
            box.pop_front();
            row++;
        }
        result[count++] = box.front();
        box.pop_front();
    }
    cout << "<" << result[0];
    for (int i = 1; i < n; i++)
        cout << ", " << result[i];
    cout << ">\n";
    delete[] result;
    return 0;
}