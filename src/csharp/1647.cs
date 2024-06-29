// 백준 1647번 문제 : 도시 분할 계획
// https://www.acmicpc.net/problem/1647
// 알고리즘 분류 : 그래프 이론, 최소 스패닝 트리

// Kruskal's Algorithm

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var houses = new int[conditions[0] + 1];
int setCount = conditions[0];
Array.Fill(houses, -1);
int minResult = 0;

var pq = new PriorityQueue<(int s, int d), int>();

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    pq.Enqueue((temp[0], temp[1]), temp[2]);
}

while (pq.Count > 0 && setCount > 2)
{
    pq.TryDequeue(out var edge, out int cost);
    if (UnionSet(houses, edge.s, edge.d))
        minResult += cost;
}
Console.WriteLine(minResult);

bool UnionSet(int[] arr, int a, int b)
{
    int aRoot = FindSet(arr, a);
    int bRoot = FindSet(arr, b);

    if (aRoot == bRoot) return false;

    if (arr[bRoot] < arr[aRoot])
        arr[aRoot] = bRoot;
    else
    {
        if (arr[aRoot] == arr[bRoot])
            arr[aRoot]--;
        arr[bRoot] = aRoot;
    }
    setCount--;
    return true;
}

int FindSet(int[] arr, int target)
{
    if (arr[target] < 0)
        return target;
    return arr[target] = FindSet(arr, arr[target]);
}
