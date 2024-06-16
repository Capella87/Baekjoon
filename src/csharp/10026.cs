// 백준 10026번 문제 : 적록색약
// https://www.acmicpc.net/problem/10026
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

var yMove = new[] { 0, 1, 0, -1 };
var xMove = new[] { 1, 0, -1, 0 };
int zoneCount = 0, colorBlindZoneCount = 0;

int n = int.Parse(Console.ReadLine());
var board = new string[n];
var isVisited = new bool[n, n, 2];

for (int i = 0; i < n; i++)
    board[i] = Console.ReadLine();
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (!isVisited[i, j, 0])
        {
            BFS(i, j);
            zoneCount++;
        }
        if (!isVisited[i, j, 1])
        {
            BFS(i, j, 1);
            colorBlindZoneCount++;
        }
    }
}
Console.WriteLine($"{zoneCount} {colorBlindZoneCount}");

void BFS(int y, int x, int isColorBlind = 0)
{
    var q = new Queue<(int y, int x)>();
    isVisited[y, x, isColorBlind] = true;
    q.Enqueue((y, x));
    char initColor = (isColorBlind == 1 && board[y][x] != 'B') ? 'A' : board[y][x];

    while (q.Count > 0)
    {
        (y, x) = q.Dequeue();
        for (int i = 0; i < 4; i++)
        {
            int newY = y + yMove[i];
            int newX = x + xMove[i];

            if (newX < 0 || newY < 0 || newX >= n || newY >= n) continue;
            if (!isVisited[newY, newX, isColorBlind] && ((initColor == 'A' && board[newY][newX] != 'B') || board[newY][newX] == initColor))
            {
                isVisited[newY, newX, isColorBlind] = true;
                q.Enqueue((newY, newX));
            }
        }
    }
}
