// 백준 13549번 문제 : 최소비용 구하기
// https://www.acmicpc.net/problem/1916
// 알고리즘 분류 : 그래프 이론, 데이크스트라, 최단 경로

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());

// Outbound
var outbound = new List<(int, int)>[n + 1];
// MinimumCost
var minimumCosts = new int[n + 1];

var pq = new PriorityQueue<int, int>();

for (int i = 1; i <= n; i++)
{
    outbound[i] = new List<(int, int)>();
    minimumCosts[i] = int.MaxValue;
}

for (int i = 0; i < m; i++)
{
    // temp[0] = departure, temp[1] = destination, temp[2] = cost
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    outbound[temp[0]].Add((temp[1], temp[2]));
}

var route = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
minimumCosts[route[0]] = 0;
pq.Enqueue(route[0], 0);

int city, cost, tcost;

while (pq.Count > 0)
{
    pq.TryDequeue(out city, out cost);

    if (city == route[1])
        break;

    if (minimumCosts[city] < cost)
        continue;

    for (int i = 0; i < outbound[city].Count; i++)
    {
        tcost = cost + outbound[city][i].Item2;

        if (tcost < minimumCosts[outbound[city][i].Item1])
        {
            pq.Enqueue(outbound[city][i].Item1, tcost);
            minimumCosts[outbound[city][i].Item1] = tcost;
        }
    }
}

Console.WriteLine(minimumCosts[route[1]]);
