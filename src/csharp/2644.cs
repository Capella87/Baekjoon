// 백준 2644번 문제 : 촌수계산
// https://www.acmicpc.net/problem/2644
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System.Text;

int n = int.Parse(Console.ReadLine());

var arr = new List<int>[n + 1];
for (int i = 1; i <= n; i++)
{
    arr[i] = new();
}

int[] targets = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '),
    int.Parse);

int m = int.Parse(Console.ReadLine());
for (int i = 0; i < m; i++)
{
    int[] temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '),
        int.Parse);
    arr[temp[0]].Add(temp[1]);
    arr[temp[1]].Add(temp[0]);
}

// Do BFS from targets[0] to targets[1];

Console.WriteLine(BFS(arr, 
    n,
    targets[0], 
    targets[1]));

int BFS(List<int>[] connections, int n, int departure, int destination)
{
    var q = new Queue<(int, int)>();
    q.Enqueue((departure, 0));
    var isVisited = new bool[n + 1];
    isVisited[departure] = true;
    int point, chon = 0;

    while (q.Count > 0)
    {
        (point, chon) = q.Dequeue();

        if (point == destination)
        {
            return chon;
        }

        for (int i = 0; i < connections[point].Count; i++)
        {
            if (!isVisited[connections[point][i]])
            {
                q.Enqueue((connections[point][i], chon + 1));
                isVisited[connections[point][i]] = true;
            }
        }
    }

    return -1;
}
