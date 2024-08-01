// 백준 1922번 문제 : 네트워크 연결
// https://www.acmicpc.net/problem/1922
// 알고리즘 분류 : 그래프 이론, 최소 스패닝 트리

// Kruskal's Algorithm

int n = int.Parse(Console.ReadLine());
int m = int.Parse(Console.ReadLine());
var pq = new PriorityQueue<(int Src, int Dest), int>();
var arr = new int[n + 1];
Array.Fill(arr, -1);

for (int i = 0; i < m; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    pq.Enqueue((temp[0], temp[1]), temp[2]);
}

int minimumCost = 0;
while (pq.Count > 0)
{
    pq.TryDequeue(out var edge, out int cost);

    if (UnionNode(arr, edge.Src, edge.Dest))
        minimumCost += cost;
}
Console.WriteLine(minimumCost);

int FindRoot(int[] nodes, int target)
{
    if (nodes[target] < 0)
        return target;
    else return nodes[target] = FindRoot(nodes, nodes[target]);
}

bool UnionNode(int[] nodes, int a, int b)
{
    int aRoot = FindRoot(nodes, a);
    int bRoot = FindRoot(nodes, b);

    if (aRoot == bRoot) return false;

    if (nodes[bRoot] < nodes[aRoot])
        nodes[aRoot] = bRoot;
    else
    {
        if (nodes[aRoot] == nodes[bRoot])
            nodes[aRoot]--;
        nodes[bRoot] = aRoot;
    }
    return true;
}
