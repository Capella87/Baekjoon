// 백준 1926번 문제 : 그림
// https://www.acmicpc.net/problem/1926
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

int[] xMove = new[] { 1, 0, -1, 0 };
int[] yMove = new[] { 0, 1, 0, -1 };

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var painting = new List<int[]>();
var visitStatusMap = new bool[conditions[0], conditions[1]];
int mxArea = 0, count = 0;
for (int i = 0; i < conditions[0]; i++)
    painting.Add(Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse));

for (int i = 0; i < conditions[0]; i++)
{
    for (int j = 0; j < conditions[1]; j++)
    {
        if (!visitStatusMap[i, j] && painting[i][j] == 1)
        {
            visitStatusMap[i, j] = true;
            mxArea = Math.Max(mxArea, BFS(i, j));
            count++;
        }
    }
}
Console.WriteLine($"{count}\n{mxArea}");

int BFS(int i, int j)
{
    int area = 1;
    var q = new Queue<(int y, int x)>();
    q.Enqueue((i, j));
    while (q.Count > 0)
    {
        var (y, x) = q.Dequeue();
        for (int k = 0; k < 4; k++)
        {
            int newY = y + yMove[k];
            int newX = x + xMove[k];

            if (newY < 0 || newY >= conditions[0] || newX < 0 || newX >= conditions[1])
                continue;
            if (!visitStatusMap[newY, newX] && painting[newY][newX] == 1)
            {
                visitStatusMap[newY, newX] = true;
                area++;
                q.Enqueue((newY, newX));
            }
        }
    }
    return area;
}
