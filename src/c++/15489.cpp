// 백준 15489번 문제 : 파스칼 삼각형
// https://www.acmicpc.net/problem/15489
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론

#include <iostream>
using namespace std;

int binomial_total(int r, int c, int w)
{
    // Get the number of vertex;
    int arr[31]{ 0, };
    arr[0] = 1;
    
    for (int i = 1; i < r; i++)
    {
        int j = 30;
        while (j > 0)
        {
            arr[j] = arr[j - 1] + arr[j];
            j--;
        }
    }
    int pos = c - 1;
    int total = arr[pos];
    int story_count = 2;

    for (int i = 1; i < w; i++, story_count++)
    {
        int j = 30;
        while (j > 0)
        {
            arr[j] = arr[j - 1] + arr[j];
            if (j >= pos && j < (pos + story_count))
                total += arr[j];
            j--;
        }
        if (pos == 0) total += 1;
    }

    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c, w;
    cin >> r >> c >> w;
    cout << binomial_total(r, c, w);

    return 0;
}