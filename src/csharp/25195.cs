// 백준 25195번 문제 : Yes or Yes
// https://www.acmicpc.net/problem/25195
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

// conditions[0] for n (the number of vertices), conditions[1] for m (the number of edges)
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var nodes = new List<int>[conditions[0] + 1];
var isVisited = new bool[conditions[0] + 1];
var fanInfo = new bool[conditions[0] + 1];

for (int i = 1; i <= conditions[0]; i++)
{
    nodes[i] = new List<int>();
}

for (int i = 0; i < conditions[1]; i++)
{
    var n = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    nodes[n[0]].Add(n[1]);
}
var fanCount = int.Parse(Console.ReadLine());
var fans = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
for (int i = 0; i < fans.Length; i++)
{
    fanInfo[fans[i]] = true;
}

if (fanInfo[1])
{
    Console.WriteLine("Yes");
    return;
}

bool hasToMeetGom = false;
var q = new Queue<int>();
q.Enqueue(1);
while (q.Count > 0)
{
    int vertex = q.Dequeue();
    isVisited[vertex] = true;

    if (nodes[vertex].Count == 0)
    {
        hasToMeetGom = false;
        break;
    }

    foreach (var v in nodes[vertex])
    {
        if (!fanInfo[v] && !isVisited[v])
            q.Enqueue(v);
        else if (fanInfo[v] && !isVisited[v])
            hasToMeetGom = true;
    }
}

Console.WriteLine(hasToMeetGom ? "Yes" : "yes");
