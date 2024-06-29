// 백준 1584번 문제 : 게임
// https://www.acmicpc.net/problem/1584
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 데이크스트라, 최단 경로, 0-1 너비 우선 탐색

// Solution using 0-1 BFS

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <memory>
#include <new>
#include <deque>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

const int xMove[4] = { 0, 1, 0, -1 };
const int yMove[4] = { 1, 0, -1, 0 };

int zoneMap[501][501];
int visitStatusMap[501][501];
bool isVisited[501][501];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c1x, c1y, c2x, c2y;
        cin >> c1x >> c1y >> c2x >> c2y;
        int startX = MIN(c1x, c2x), startY = MIN(c1y, c2y);
        int endX = MAX(c1x, c2x), endY = MAX(c1y, c2y);
        for (int j = startX; j <= endX; j++)
            for (int k = startY; k <= endY; k++)
                zoneMap[j][k] = -1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int c1x, c1y, c2x, c2y;
        cin >> c1x >> c1y >> c2x >> c2y;
        int startX = MIN(c1x, c2x), startY = MIN(c1y, c2y);
        int endX = MAX(c1x, c2x), endY = MAX(c1y, c2y);
        for (int j = startX; j <= endX; j++)
            for (int k = startY; k <= endY; k++)
                zoneMap[j][k] = visitStatusMap[j][k] = -2;
    }
    zoneMap[0][0] = visitStatusMap[0][0] = 0;

    deque<tuple<int, int, int>> q;
    q.push_back({ 0, 0, 0 });

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop_front();
        int x = get<0>(cur), y = get<1>(cur), lifeLostCount = get<2>(cur);

        if (lifeLostCount != visitStatusMap[x][y]) continue;
        if (x == 500 && y == 500) break;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + xMove[i];
            int newY = y + yMove[i];
            if (newY < 0 || newY > 500 || newX < 0 || newX > 500) continue;
            if (zoneMap[newX][newY] == -2) continue;

            int newLostCount = (zoneMap[newX][newY] == -1) ? 1 : 0;
            if (!isVisited[newX][newY] || visitStatusMap[newX][newY] > (lifeLostCount + newLostCount))
            {
                visitStatusMap[newX][newY] = lifeLostCount + newLostCount;
                isVisited[newX][newY] = true;
                if (newLostCount == 0) q.push_front({ newX, newY, visitStatusMap[newX][newY] });
                else q.push_back({ newX, newY, visitStatusMap[newX][newY] });
            }
        }
    }
    if (!isVisited[500][500]) cout << -1 << '\n';
    else cout << visitStatusMap[500][500] << '\n';
    return 0;
}
