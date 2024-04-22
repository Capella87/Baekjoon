// 백준 7511번 문제 : 소셜 네트워킹 어플리케이션
// https://www.acmicpc.net/problem/7511
// 알고리즘 분류 : 자료 구조, 그래프 이론, 분리 집합

using System.Text;

int t = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

for (int j = 1; j <= t; j++)
{
    int n = int.Parse(Console.ReadLine());
    int k = int.Parse(Console.ReadLine());

    var sets = new int[n + 1];
    Array.Fill(sets, -1);

    for (int i = 0; i < k; i++)
    {
        var relation = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
        UnionSet(sets, relation[0], relation[1]);
    }

    sb.AppendLine($"Scenario {j}:");
    int m = int.Parse(Console.ReadLine());
    for (int i = 0; i < m; i++)
    {
        var relation = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
        sb.AppendLine(HasConnection(sets, relation[0], relation[1]) ? "1" : "0");
    }
    sb.Append('\n');
}

Console.Write(sb.ToString());

bool UnionSet(int[] elements, int a, int b)
{
    int aRoot = FindSet(elements, a);
    int bRoot = FindSet(elements, b);

    if (aRoot == bRoot)
        return false;

    if (elements[aRoot] < elements[bRoot])
    {
        elements[bRoot] = aRoot;
    }
    else
    {
        if (elements[aRoot] == elements[bRoot])
            --elements[bRoot];
        elements[aRoot] = bRoot;
    }

    return true;
}

int FindSet(int[] elements, int target)
{
    if (elements.Length <= target) return -1;

    if (elements[target] < 0) return target;
    else return elements[target] = FindSet(elements, elements[target]);
}

bool HasConnection(int[] network, int a, int b)
{
    return FindSet(network, a) == FindSet(network, b);
}
