// 백준 2623번 문제 : 음악프로그램
// https://www.acmicpc.net/problem/2623
// 알고리즘 분류 : 그래프 이론, 위상 정렬, 방향 비순환 그래프

// Topological Sort with DFS

using System.Text;

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var artists = new List<int>[conditions[0] + 1];
short number = (short)conditions[0];
var order = new int[conditions[0] + 1];
var isVisited = new short[conditions[0] + 1];
bool hasCycle = false;

for (int i = 1; i <= conditions[0]; i++)
    artists[i] = new List<int>();
for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    for (int j = 1; j < temp[0]; j++)
        artists[temp[j]].Add(temp[j + 1]);
}

for (int i = 1; i <= conditions[0]; i++)
{
    if (isVisited[i] != 0) continue;
    isVisited[i] = -1;
    for (int j = 0; j < artists[i].Count && !hasCycle; j++)
    {
        if (isVisited[artists[i][j]] == 0)
            hasCycle = FindOrderRecursive(artists[i][j]);
    }
    if (hasCycle)
    {
        Console.WriteLine("0");
        return;
    }
    order[number] = i;
    isVisited[i] = number--;
}
var sb = new StringBuilder();
for (int i = 1; i <= conditions[0]; i++)
    sb.AppendLine($"{order[i]}");
Console.Write(sb.ToString());

bool FindOrderRecursive(int dest)
{
    if (isVisited[dest] == -1) return true;
    isVisited[dest] = -1;
    bool hasCycle = false;
    for (int i = 0; i < artists[dest].Count && !hasCycle; i++)
    {
        if (isVisited[artists[dest][i]] <= 0)
            hasCycle = FindOrderRecursive(artists[dest][i]);
    }
    if (hasCycle) return true;
    order[number] = dest;
    isVisited[dest] = number--;
    return false;
}
