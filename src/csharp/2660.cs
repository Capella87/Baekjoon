// 백준 2660번 문제 : 회장뽑기
// https://www.acmicpc.net/problem/2660
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 최단 경로, 플로이드-워셜

using System.Text;

int n = int.Parse(Console.ReadLine());
var network = new int[n + 1, n + 1];
var scoreBoard = new int[n + 1];
while (true)
{
    var cond = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
    if (cond[0] == -1) break;
    network[cond[0], cond[1]] = 1;
    network[cond[1], cond[0]] = 1;
}

for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (i == j) continue;
        for (int k = 1; k <= n; k++)
        {
            if (i == k || j == k) continue;
            if (network[i, j] > 0 && network[j, k] > 0)
            {
                if (network[i, k] == 0)
                {
                    network[i, k] = network[i, j] + network[j, k];
                    network[k, i] = network[i, k];
                }
                else if (network[i, k] > 1)
                {
                    network[i, k] = Math.Min(network[i, k], network[i, j] + network[j, k]);
                    network[k, i] = network[i, k];
                }
            }
        }
    }
}

int leader = int.MaxValue;
var candidates = new List<int>();
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
        if (i == j) continue;
        scoreBoard[i] = Math.Max(scoreBoard[i], network[i, j]);
    }
}
for (int i = 1; i <= n; i++)
    leader = Math.Min(leader, scoreBoard[i]);
for (int i = 1; i <= n; i++)
    if (scoreBoard[i] == leader)
        candidates.Add(i);
candidates.Sort();
var sb = new StringBuilder();
sb.AppendLine($"{leader} {candidates.Count}");
candidates.ForEach((item) => sb.Append($"{item} "));
sb.Append('\n');
Console.Write(sb.ToString());
