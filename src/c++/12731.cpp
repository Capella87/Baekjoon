// 백준 12731번 문제 : 열차 시간표(Small)
// https://www.acmicpc.net/problem/12731
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 우선순위 큐

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int parse_time(string& str, const int begin, const int end)
{
    int rt = stoi(str.substr(begin, 2)) * 60;
    return rt + stoi(str.substr(begin + 3, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, t;
    int na, nb;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        priority_queue<int, vector<int>, greater<int>> a, b;
        vector<pair<int, int>> A, B;
        string input;

        cin >> t >> na >> nb;
        cin.get();
        for (int j = 0; j < na; j++)
        {
            getline(cin, input);
            // Parse
            int temp = parse_time(input, 6, 10);
            A.push_back(make_pair(parse_time(input, 0, 4), temp));
            b.push(temp + t);
        }
        if (!A.empty())sort(A.begin(), A.end());
        for (int j = 0; j < nb; j++)
        {
            getline(cin, input);
            // Parse
            int temp = parse_time(input, 6, 10);
            B.push_back(make_pair(parse_time(input, 0, 4), temp));
            a.push(temp + t);
        }
        if (!B.empty()) sort(B.begin(), B.end());

        int size = int(A.size());
        int a_required = 0, b_required = 0;
        for (int j = 0; j < size; j++)
        {
            if (a.empty() || a.top() > A[j].first)
                a_required++;
            else a.pop();
        }
        size = int(B.size());
        for (int j = 0; j < size; j++)
        {
            if (b.empty() || b.top() > B[j].first)
                b_required++;
            else b.pop();
        }

        cout << "Case #" << i + 1 << ": " << a_required << ' ' << b_required << '\n';
    }
    return 0;
}