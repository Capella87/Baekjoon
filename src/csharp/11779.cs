// 백준 11779번 문제 : 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779
// 알고리즘 분류 : 그래프 이론, 데이크스트라, 최단 경로

using System.Text;

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());

var network = new List<(int d, int c)>[n + 1];
for (int i = 1; i <= n; i++)
    network[i] = new List<(int d, int w)>();
var distanceMap = new int[n + 1];
Array.Fill(distanceMap, -1);
// Save previous point
var pathMap = new int[n + 1];

for (int i = 0; i < m; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    network[temp[0]].Add((temp[1], temp[2]));
}
var nav = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var pq = new PriorityQueue<int, int>();
distanceMap[nav[0]] = 0;
pq.Enqueue(nav[0], 0);

while (pq.Count > 0)
{
    pq.TryDequeue(out int point, out int cost);

    // Skip the point if the current point's cost is already refreshed by other better path
    if (distanceMap[point] < cost) continue;

    for (int i = 0; i < network[point].Count; i++)
    {
        int newCost = cost + network[point][i].c;
        if (distanceMap[network[point][i].d] == -1 || newCost < distanceMap[network[point][i].d])
        {
            pq.Enqueue(network[point][i].d, newCost);
            distanceMap[network[point][i].d] = newCost;
            pathMap[network[point][i].d] = point;
        }
    }
}

var sb = new StringBuilder();
var l = new List<int>();
sb.Append($"{distanceMap[nav[1]]}\n");
int p = nav[1];

while (distanceMap[p] != 0)
{
    l.Add(p);
    p = pathMap[p];
}

l.Add(nav[0]);
sb.Append($"{l.Count}\n");
for (int i = l.Count - 1; i >= 0; i--)
    sb.Append($"{l[i]} ");

Console.WriteLine(sb.ToString());
