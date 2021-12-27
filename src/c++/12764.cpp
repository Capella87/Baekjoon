// 백준 12764번 문제 : 싸지방에 간 준하
// https://www.acmicpc.net/problem/12764
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pc_bang; // Schedule
    priority_queue<int, vector<int>, greater<int>> empty_slot;
    vector<pair<int, int>> people;
    vector<int> required;
    int n, start, end, time = 0;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        people.push_back(make_pair(start, end));
    }
    sort(people.begin(), people.end());

    for (int i = 0; i < n; i++)
    {
        time = people[i].first;
        while (!pc_bang.empty() && pc_bang.top().first <= time) // Pop completed schedules
        {
            int num = pc_bang.top().second;
            pc_bang.pop();
            empty_slot.push(num);
        }

        if (empty_slot.empty()) // No empty slots
        {
            required.push_back(1); // Make a new slot
            pc_bang.push(make_pair(people[i].second, int(required.size()) - 1));
        }
        else // Empty slots
        {
            int num = empty_slot.top();
            empty_slot.pop();
            required[num]++; // Count the number of slot usage
            pc_bang.push(make_pair(people[i].second, num)); // Push it into the heap
        }
    }

    int size = int(required.size()); // Minimum required slots
    cout << size << '\n';
    for (int i = 0; i < size; i++)
        cout << required[i] << ' ';
    cout << '\n';

    return 0;
}