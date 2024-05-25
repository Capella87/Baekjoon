// 백준 1504번 문제 : 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
// 알고리즘 분류 : 데이크스트라, 그래프 이론, 최단 경로

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var edges = new List<(int, int)>[conditions[0] + 1];

for (int i = 1; i <= conditions[0]; i++)
    edges[i] = new List<(int, int)>();

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

    edges[temp[0]].Add((temp[1], temp[2]));
    edges[temp[1]].Add((temp[0], temp[2]));
}
var mandatoryVertices = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

long firstOptionDistance = GetDistance(edges, conditions[0], mandatoryVertices[0], mandatoryVertices[1])
    + GetDistance(edges, conditions[0], 1, mandatoryVertices[0])
    + GetDistance(edges, conditions[0], mandatoryVertices[1], conditions[0]);
long secondOptionDistance = GetDistance(edges, conditions[0], mandatoryVertices[1], mandatoryVertices[0])
    + GetDistance(edges, conditions[0], 1, mandatoryVertices[1])
    + GetDistance(edges, conditions[0], mandatoryVertices[0], conditions[0]);

Console.WriteLine(firstOptionDistance >= int.MaxValue && secondOptionDistance >= int.MaxValue
    ? -1 : Math.Min(firstOptionDistance, secondOptionDistance));

long GetDistance(List<(int, int)>[] edges, int n, int src, int dest)
{
    var distances = new int[n + 1];
    Array.Fill(distances, int.MaxValue);

    var pq = new PriorityQueue<int, int>();
    distances[src] = 0;
    pq.Enqueue(src, 0);
    int currentDistance, vertex;

    while (pq.Count > 0)
    {
        pq.TryDequeue(out vertex, out currentDistance);

        if (distances[vertex] < currentDistance)
            continue;

        for (int i = 0; i < edges[vertex].Count; i++)
        {
            int nextDistance = currentDistance + edges[vertex][i].Item2;
            if (nextDistance < distances[edges[vertex][i].Item1])
            {
                distances[edges[vertex][i].Item1] = nextDistance;
                pq.Enqueue(edges[vertex][i].Item1, nextDistance);
            }
        }
    }

    return distances[dest];
}
