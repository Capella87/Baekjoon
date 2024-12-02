// 백준 1946번 문제 : 신입 사원
// https://www.acmicpc.net/problem/1946
// 알고리즘 분류 : 그리디 알고리즘, 정렬

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        vector <pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());

        int highest = v[0].second;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second < highest)
            {
                count++;
                highest = v[i].second;
            }
        }
        cout << count << '\n';
        t--;
    }
    return 0;
}
