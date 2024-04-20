// 백준 20040번 문제 : 사이클 게임
// https://www.acmicpc.net/problem/20040
// 알고리즘 분류 : 자료 구조, 분리 집합

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var vertices = new int[conditions[0]];
Array.Fill(vertices, -1);
bool hasCycle = false;
int cycleDetectedOrder = 0;

for (int i = 0; i < conditions[1]; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

    hasCycle = !UnionSet(vertices, temp[0], temp[1]);
    if (hasCycle)
    {
        cycleDetectedOrder = i + 1;
        break;
    }
}

Console.WriteLine(cycleDetectedOrder);

bool UnionSet(int[] arr, int a, int b)
{
    int aRoot = FindSet(arr, a);
    int bRoot = FindSet(arr, b);

    if (aRoot == bRoot || aRoot == -1 || bRoot == -1) return false;

    if (arr[bRoot] < arr[aRoot])
    {
        arr[aRoot] = bRoot;
    }
    else
    {
        if (arr[aRoot] == arr[bRoot])
            --arr[aRoot];
        arr[bRoot] = aRoot;
    }

    return true;
}

int FindSet(int[] arr, int target)
{
    if (arr.Length <= target) return -1;

    if (arr[target] < 0) return target;
    else return arr[target] = FindSet(arr, arr[target]);
}
