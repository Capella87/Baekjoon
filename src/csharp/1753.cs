// 백준 1753번 문제 : 최단경로
// https://www.acmicpc.net/problem/1753
// 알고리즘 분류 : 그래프 이론, 데이크스트라, 최단 경로

using System.Text;

// Dijkstra's Algorithm

// conditions[0] = v, and conditions[1] = e
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
int k = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

var vertices = new List<(int dest, int distance)>[conditions[0] + 1];
var distances = new int[conditions[0] + 1];
for (int i = 1; i <= conditions[0]; i++)
{
    distances[i] = int.MaxValue;
    vertices[i] = new List<(int dest, int distance)>();
}
var pq = new PriorityQueue<int, int>();
int vertex, weight;
distances[k] = 0;

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    vertices[temp[0]].Add((temp[1], temp[2]));
}

pq.Enqueue(k, 0);
while (pq.Count > 0)
{
    pq.TryDequeue(out vertex, out weight);

    if (weight > distances[vertex])
        continue;
    
    for (int i = 0; i < vertices[vertex].Count; i++)
    {
        int nextWeight = weight + vertices[vertex][i].distance;
        
        if (nextWeight < distances[vertices[vertex][i].dest])
        {
            pq.Enqueue(vertices[vertex][i].dest, nextWeight);
            distances[vertices[vertex][i].dest] = nextWeight;
        }
    }
}

for (int i = 1; i <= conditions[0]; i++)
{
    sb.AppendLine(distances[i] == int.MaxValue ? "INF" : distances[i].ToString());
}

Console.Write(sb.ToString());
