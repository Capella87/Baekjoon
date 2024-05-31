// 백준 11404번 문제 : 플로이드
// https://www.acmicpc.net/problem/11404
// 알고리즘 분류 : 그래프 이론, 최단 경로, 플로이드-워셜

using System.Text;

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());
var sb = new StringBuilder();
var cityNetwork = new int[n + 1, n + 1];

for (int i = 0; i < m; i++)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    if (cityNetwork[conditions[0], conditions[1]] == 0 || conditions[2] < cityNetwork[conditions[0], conditions[1]])
        cityNetwork[conditions[0], conditions[1]] = conditions[2];
}

// Do Floyd-Warshall algorithm

// Stopover vertex
for (int i = 1; i <= n; i++)
{
    // Source
    for (int j = 1; j <= n; j++)
    {
        if (j == i) continue;
        // Destination
        for (int k = 1; k <= n; k++)
        {
            if (k == j || k == i) continue;
            if (cityNetwork[j, i] != 0 && cityNetwork[i, k] != 0)
            {
                int totalStopoverCost = cityNetwork[j, i] + cityNetwork[i, k];
                if (cityNetwork[j, k] == 0 || totalStopoverCost < cityNetwork[j, k])
                    cityNetwork[j, k] = totalStopoverCost;
            }
        }
    }
}

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
        sb.Append($"{cityNetwork[i, j]} ");
    sb.Append('\n');
}

Console.Write(sb.ToString());
