// 백준 2252번 문제 : 줄 세우기
// https://www.acmicpc.net/problem/2252
// 알고리즘 분류 : 그래프 이론, 위상 정렬, 방향 비순환 그래프

using System.Text;

var cond = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var outbound = new List<int>[cond[0] + 1];
var inbound = new List<int>[cond[0] + 1];
for (int i = 1; i <= cond[0]; i++)
{
    outbound[i] = new List<int>();
    inbound[i] = new List<int>();
}

for (int i = 0; i < cond[1]; i++)
{
    var edge = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
    outbound[edge[1]].Add(edge[0]);
    inbound[edge[0]].Add(edge[1]);
}

var result = SortPeople();

Console.WriteLine(result.ToString());

StringBuilder SortPeople()
{
    var sb = new StringBuilder();

    var isVisited = new bool[cond[0] + 1];


    // Do DFS
    for (int i = 1; i <= cond[0]; i++)
    {
        if (!isVisited[i] && inbound[i].Count == 0)
            DFS(isVisited, sb, i);
    }

    return sb;
}

void DFS(bool[] isVisited, StringBuilder sb, int node)
{
    isVisited[node] = true;

    foreach (var dest in outbound[node])
    {
        if (!isVisited[dest])
            DFS(isVisited, sb, dest);
    }

    sb.Append($"{node} ");
}
