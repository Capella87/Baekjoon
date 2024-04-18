// 백준 16747번 문제 : 서울 지하철 2호선
// https://www.acmicpc.net/problem/16947
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

int n = int.Parse(Console.ReadLine());

var stations = new List<int>[n + 1];
for (int i = 1; i <= n; i++)
{
    stations[i] = new List<int>();
}

var distanceFromLoop = new int[n + 1];
var isVisited = new bool[n + 1];
Array.Fill(distanceFromLoop, -1);

for (int i = 0; i < n; i++)
{
    var temp = Console.ReadLine().Split();

    int source = int.Parse(temp[0]);
    int destination = int.Parse(temp[1]);

    stations[source].Add(destination);
    stations[destination].Add(source);
}

var stk = new Stack<(int v, int prev)>();
var interchanges = new Queue<(int v, int prev)>();
stk.Push((1, 1));
distanceFromLoop[1] = -2;
int v, previous;
bool hasCycle = false;
int cycleStartVertex = 0;

while (stk.Count > 0)
{
    (v, previous) = stk.Peek();

    if (!isVisited[v] && !hasCycle)
    {
        isVisited[v] = true;
        distanceFromLoop[v] = -2;
    }
    else if (hasCycle)
    {
        if (!isVisited[v])
            distanceFromLoop[v] = -1;
        else
        {
            if (stations[v].Count > 2) interchanges.Enqueue((v, v));
            distanceFromLoop[v] = 0;
        }

        stk.Pop();

        if (v == cycleStartVertex) break;
        continue;
    }
    else
    {
        distanceFromLoop[v] = -1;
        stk.Pop();
        continue;
    }

    for (int i = 0; i < stations[v].Count; i++)
    {
        if (!isVisited[stations[v][i]])
        {
            stk.Push((stations[v][i], v));
            distanceFromLoop[stations[v][i]] = -2;
        }
        else if (stations[v][i] == previous) continue;
        // Finally find a cycle
        else if (distanceFromLoop[stations[v][i]] == -2)
        {
            hasCycle = true;
            cycleStartVertex = stations[v][i];
            break;
        }
    }
}

while (interchanges.Count > 0)
{
    (v, previous) = interchanges.Dequeue();

    for (int i = 0; i < stations[v].Count; i++)
    {
        if (previous == stations[v][i]) continue;

        if (distanceFromLoop[stations[v][i]] < 0)
        {
            distanceFromLoop[stations[v][i]] = distanceFromLoop[v] + 1;
            interchanges.Enqueue((stations[v][i], v));
        }
    }
}

for (int i = 1; i <= n; i++)
    Console.Write($"{distanceFromLoop[i]} ");
Console.Write('\n');
