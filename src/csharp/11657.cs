// 백준 11657번 문제 : 타임머신
// https://www.acmicpc.net/problem/11657
// 알고리즘 분류 : 그래프 이론, 최단 경로, 벨만-포드

using System.Text;

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var distances = new long[conditions[0] + 1];
Array.Fill(distances, int.MaxValue);
distances[1] = 0;
var edges = new List<(int Src, int Dest, int W)>();
bool IsInfiniteTimeSlip = false;

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    edges.Add((temp[0], temp[1], temp[2]));
}

for (int i = 1; i < conditions[0]; i++)
{
    foreach (var edge in edges)
    {
        // Skip not calculated edges from the first vertex
        if (distances[edge.Src] == int.MaxValue) continue;
        distances[edge.Dest] = Math.Min(distances[edge.Dest], distances[edge.Src] + edge.W);
    }
}

// Detect any negative cycle (Infinite time slip)
foreach (var edge in edges)
{
    if (distances[edge.Src] == int.MaxValue) continue;

    if (distances[edge.Dest] > (distances[edge.Src] + edge.W))
    {
        IsInfiniteTimeSlip = true;
        break;
    }
}

if (IsInfiniteTimeSlip)
{
    Console.WriteLine(-1);
    return;
}

var sb = new StringBuilder();
for (int i = 2; i <= conditions[0]; i++)
    sb.AppendLine(distances[i] == int.MaxValue ? "-1" : $"{distances[i]}");
Console.Write(sb.ToString());
