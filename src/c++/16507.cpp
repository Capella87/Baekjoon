// 백준 16507번 문제 : 어두운 건 무서워
// https://www.acmicpc.net/problem/16507
// 알고리즘 분류 : 누적 합

#include <iostream>
using namespace std;

int cache[1001][1001]{ 0, };

int get_result(int s_y, int s_x, int e_y, int e_x)
{
    int result = cache[e_y][e_x] + cache[s_y - 1][s_x - 1] - cache[e_y][s_x - 1] - cache[s_y - 1][e_x];
    result /= ((e_y - s_y + 1) * (e_x - s_x + 1));

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int r, c, q, temp;
    int start_y, start_x, end_y, end_x;
    
    cin >> r >> c >> q;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)        
        {
            cin >> temp;
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1] + temp - cache[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> start_y >> start_x >> end_y >> end_x;
        cout << get_result(start_y, start_x, end_y, end_x) << '\n';
    }

    return 0;
}