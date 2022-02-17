// 백준 20301번 문제 : 반전 요세푸스
// https://www.acmicpc.net/problem/20301
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 덱

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, m;
    bool is_clockwise = true;
    deque<int> josephus;

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        josephus.push_back(i + 1);
    int count = 1, begin = 0, removed_count = 0;

    while (!josephus.empty())
    {
        if (is_clockwise)
        {
            while (count < k)
            {
                josephus.push_back(josephus.front());
                josephus.pop_front();
                count++;
            }
            cout << josephus.front() << '\n';
            josephus.pop_front();

        }
        else
        {
            while (count < k)
            {
                josephus.push_front(josephus.back());
                josephus.pop_back();
                count++;
            }
            cout << josephus.back() << '\n';
            josephus.pop_back();
        }
        removed_count++;
        if(removed_count % m == 0)
            is_clockwise = !is_clockwise;
        count = 1;
    }

    return 0;
}