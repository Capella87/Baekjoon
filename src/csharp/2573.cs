// 백준 2573번 문제 : 빙산
// https://www.acmicpc.net/problem/2573
// 알고리즘 분류 : 구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

var yMove = new[] { 0, 1, 0, -1 };
var xMove = new[] { 1, 0, -1, 0 };
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var map = new List<int[]>();

for (int i = 0; i < conditions[0]; i++)
{
    var row = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    map.Add(row);
}

int years = 0, glaciers = 0;
do
{
    glaciers = Simulate();
    years++;
} while (glaciers == 1);
switch (glaciers)
{
    case > 1:
        Console.WriteLine(years);
        break;
    default:
        Console.WriteLine(0);
        break;
}

int Simulate()
{
    var zeroMap = new bool[conditions[0], conditions[1]];
    var visitStatusMap = new bool[conditions[0], conditions[1]];

    for (int i = 1; i < conditions[0]; i++)
    {
        for (int j = 1; j < conditions[1]; j++)
        {
            if (map[i][j] == 0) continue;
            int zeroCount = 0;
            for (int k = 0; k < 4; k++)
            {
                int newY = i + yMove[k];
                int newX = j + xMove[k];
                if (newY < 0 || newY >= conditions[0] || newX < 0 || newX >= conditions[1])
                    continue;
                if (!zeroMap[newY, newX] && map[newY][newX] == 0)
                    zeroCount++;
            }
            map[i][j] -= zeroCount;
            map[i][j] = map[i][j] <= 0 ? 0 : map[i][j];
            zeroMap[i, j] = true;
        }
    }

    int glaciers = 0;
    for (int i = 0; i < conditions[0]; i++)
    {
        for (int j = 0; j < conditions[1]; j++)
        {
            if (!visitStatusMap[i, j] && map[i][j] > 0)
            {
                ExploreGlacier(visitStatusMap, i, j);
                glaciers++;
            }
        }
    }
    return glaciers;
}

void ExploreGlacier(bool[,] visitStatusMap, int y, int x)
{
    visitStatusMap[y, x] = true;
    var q = new Queue<(int y, int x)>();
    q.Enqueue((y, x));

    while (q.Count > 0)
    {
        var (curY, curX) = q.Dequeue();
        for (int i = 0; i < 4; i++)
        {
            int suY = curY + yMove[i];
            int suX = curX + xMove[i];
            if (suY < 0 || suY >= conditions[0] || suX < 0 || suX >= conditions[1])
                continue;
            if (!visitStatusMap[suY, suX] && map[suY][suX] > 0)
            {
                visitStatusMap[suY, suX] = true;
                q.Enqueue((suY, suX));
            }
        }
    }
}
