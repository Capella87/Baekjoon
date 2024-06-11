// 백준 4963번 문제 : 섬의 개수
// https://www.acmicpc.net/problem/4963
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System.Text;

var xMove = new[] { 1, 1, 0, -1, -1, -1, 0, 1 };
var yMove = new[] { 0, 1, 1, 1, 0, -1, -1, -1 };
var sb = new StringBuilder();

while (true)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    if (conditions[0] == 0) break;

    var map = new int[conditions[1], conditions[0]];
    var isVisited = new bool[conditions[1], conditions[0]];
    int count = 0;
    
    for (int i = 0; i < conditions[1]; i++)
    {
        var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
        for (int j = 0; j < conditions[0]; j++)
            map[i, j] = temp[j];
    }

    for (int i = 0; i < conditions[1]; i++)
    {
        for (int j = 0; j < conditions[0]; j++)
        {
            if (!isVisited[i, j] && map[i, j] == 1)
            {
                BFS(i, j, map, isVisited, conditions[1], conditions[0]);
                count++;
            }
        }
    }
    sb.Append($"{count}\n");
}
Console.Write(sb);

void BFS(int i, int j, int[,] map, bool[,] isVisited, int h, int w)
{
    var q = new Queue<(int y, int x)>();
    isVisited[i, j] = true;

    q.Enqueue((i, j));
    while (q.Count > 0)
    {
        (i, j) = q.Dequeue();

        for (int k = 0; k < 8; k++)
        {
            int newY = i + yMove[k];
            int newX = j + xMove[k];

            if (newY < 0 || newY >= h || newX < 0 || newX >= w)
                continue;
            if (!isVisited[newY, newX] && map[newY, newX] == 1)
            {
                isVisited[newY, newX] = true;
                q.Enqueue((newY, newX));
            }
        }
    }
}
