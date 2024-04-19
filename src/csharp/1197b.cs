// 백준 1197번 문제 : 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
// 알고리즘 분류 : 그래프 이론, 최소 스패닝 트리

// Kruskal Algorithm

// conditions[0] for v, conditions[1] for e
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var knapsacks = new int[conditions[0] + 1];
Array.Fill(knapsacks, -1);
var pq = new PriorityQueue<(int src, int dest), int>();
int result = 0, distance;

for (int i = 0; i < conditions[1]; i++)
{
    // temp[0] = src, temp[1] = destination, temp[2] = weight
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    pq.Enqueue((temp[0], temp[1]), temp[2]);
}

while (pq.Count > 0)
{
    pq.TryDequeue(out var edge, out distance);

    // Kruskal Algorithm can be implemented with Disjoint sets (aka Union-Find)
    if (UnionSet(knapsacks, edge.src, edge.dest))
        result += distance;
}

Console.WriteLine(result);

// Union-Find (Disjoint sets)
bool UnionSet(int[] arr, int a, int b)
{
    // Find each node's root (In other words, FindSet gets a set.. the set name itself is also a root..)
    int aRoot = FindSet(arr, a);
    int bRoot = FindSet(arr, b);

    // Fail merge when they're in the same set or out of range..
    if (aRoot == bRoot || aRoot == -1 || bRoot == -1)
        return false;

    // In UF, the absolute value of arr[i] is the depth in the set. (Not to confuse to the number of elements in the set.
    // It seems strongly to be the number of element at early stages.. such as all sets have only one element, themselves..)
    // Of course, we can express the value as the size of set, but it has more poor performance than depth expression.
    // If the value is bigger than or equal to 0, the element is in other set.
    // In this condition, bRoot set has deeper than aRoot set, So aRoot set is merged to bRoot.
    if (arr[bRoot] < arr[aRoot])
        arr[aRoot] = bRoot;
    else
    {
        // If both sets have the same depth, merge to aRoot set.
        // Since merged set will be attached at the right below of root, its depth 
        if (arr[aRoot] == arr[bRoot])
            --arr[aRoot];
        // Merge to aRoot
        arr[bRoot] = aRoot;
    }

    return true;
}

// Find "set", It can be shown as finding the root of set
int FindSet(int[] arr, int target)
{
    // Out of range
    if (arr.Length <= target)
        return -1;
    // Reached to the root
    else if (arr[target] < 0)
        return target;
    // Recursive Call; go to the parent and update to the root.
    // arr[target] is not always gueranteed to show its root.
    // So save the updated value; Memoization.
    else
        return arr[target] = FindSet(arr, arr[target]);
}
