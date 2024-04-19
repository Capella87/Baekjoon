// 백준 1197번 문제 : 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
// 알고리즘 분류 : 그래프 이론, 최소 스패닝 트리

// Prim-Jarnik Algorithm

// conditions[0] for v, conditions[1] for e
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var vertices = new List<(int d, int w)>[conditions[0] + 1];
var isVisited = new bool[conditions[0] + 1];
    var pq = new PriorityQueue<int, int>();
    int v, w, result = 0;
    for (int i = 1; i <= conditions[0]; i++)
    {
        vertices[i] = new List<(int d, int w)>();
    }

    for (int i = 0; i < conditions[1]; i++)
    {
        // temp[0] = src, temp[1] = destination, temp[2] = weight
        var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
        vertices[temp[0]].Add((temp[1], temp[2]));
        vertices[temp[1]].Add((temp[0], temp[2]));
    }

pq.Enqueue(1, 0);
// Greedy Algorithm
// It takes shorter weight edge because of it has a min heap priority queue
while (pq.Count > 0)
{
    pq.TryDequeue(out v, out w);
    
    // Skip already visited node
    if (isVisited[v])
    {
        continue;
    }

    isVisited[v] = true;
    result += w;

    for (int i = 0; i < vertices[v].Count; i++)
    {
        // Put a node to the queue if it is not visited yet
        if (!isVisited[vertices[v][i].d])
        {
            pq.Enqueue(vertices[v][i].d, vertices[v][i].w);
        }
    }
}

Console.WriteLine(result);
