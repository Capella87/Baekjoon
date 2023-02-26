// 백준 1043번 문제 : 거짓말
// https://www.acmicpc.net/problem/1043
// 알고리즘 분류 : 그래프 이론, 자료 구조, 그래프 탐색, 분리 집합

#include <iostream>
using namespace std;

int people[51];
int party[50][51]{ 0 };
bool has_effected[50]{ false, };

int find_set(int target)
{
    if (people[target] < 0) return target;
    else return people[target] = find_set(people[target]);
}

void merge_set(int src, int target)
{
    int src_root = find_set(src);
    int target_root = find_set(target);
    
    if (src_root == target_root) return;
    people[src_root] += people[target_root];
    people[target_root] = src_root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, temp, truth_count;
    int truth_root = 0;

    cin >> n >> m >> truth_count;
    fill(people, people + n + 1, -1);
    if (truth_count > 0)
    {
        cin >> truth_root;
        for (int i = 1; i < truth_count; i++)
        {
            cin >> temp;
            merge_set(truth_root, temp);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> party[i][0];
        for (int j = 1; j <= party[i][0]; j++)
        {
            cin >> party[i][j];
            if (find_set(party[i][j]) == truth_root)
                has_effected[i] = true;
            else merge_set(party[i][1], party[i][j]); // Merge untruth people
        }
        if (has_effected[i])
            for (int j = 1; j <= party[i][0]; j++)
                merge_set(truth_root, party[i][j]);
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (has_effected[i]) continue;
        for (int j = 1; j <= party[i][0]; j++)
        {
            if (find_set(party[i][j]) == truth_root)
            {
                has_effected[i] = true;
                break;
            }
        }
        if (!has_effected[i]) count++;
    }
    cout << count << '\n';

    return 0;
}