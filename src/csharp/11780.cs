// 백준 11780번 문제 : 플로이드 2
// https://www.acmicpc.net/problem/11780
// 알고리즘 분류 : 그래프 이론, 최단 경로, 플로이드-워셜

using System.Text;

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());

var stopovers = new int[n + 1, n + 1];
var cityNetwork = new int[n + 1, n + 1];
var sb = new StringBuilder();

while (m > 0)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    if (cityNetwork[conditions[0], conditions[1]] == 0 || conditions[2] < cityNetwork[conditions[0], conditions[1]])
        cityNetwork[conditions[0], conditions[1]] = conditions[2];
    m--;
}

for (int k = 1; k <= n; k++)
{
    for (int i = 1; i <= n; i++)
    {
        if (k == i) continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j || k == j) continue;

            if (cityNetwork[i, k] != 0 && cityNetwork[k, j] != 0)
            {
                int cost = cityNetwork[i, k] + cityNetwork[k, j];
                if (cityNetwork[i, j] == 0 || cost < cityNetwork[i, j])
                {
                    cityNetwork[i, j] = cost;
                    stopovers[i, j] = k;
                }
            }
        }
    }
}

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        sb.Append($"{cityNetwork[i, j]} ");
    }
    sb.Append('\n');
}

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (cityNetwork[i, j] == 0)
        {
            sb.AppendLine("0");
            continue;
        }
        var path = new List<int>();
        GetPath(path, i, j);
        sb.Append($"{path.Count} ");
        foreach (var p in path)
            sb.Append($"{p} ");
        sb.Append('\n');
    }
}
Console.Write(sb.ToString());

void GetPath(List<int> path, int i, int j)
{
    if (stopovers[i, j] == 0)
    {
        path.Add(i);
        path.Add(j);
    }
    else
    {
        GetPath(path, i, stopovers[i, j]);
        path.RemoveAt(path.Count - 1);
        GetPath(path, stopovers[i, j], j);
    }
}
