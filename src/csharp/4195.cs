// 백준 4195번 문제 : 친구 네트워크
// https://www.acmicpc.net/problem/4195
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵, 분리 집합

using System.Text;

int t = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

while (t > 0)
{
    int f = int.Parse(Console.ReadLine());
    int idx = -1, a, b, result;
    var friends = new Dictionary<string, int>();
    var setCounter = new Dictionary<int, int>();
    var friendSets = new List<int>();

    for (int i = 0; i < f; i++)
    {
        var people = Console.ReadLine().Split();

        bool isAFound = friends.TryGetValue(people[0], out a);
        bool isBFound = friends.TryGetValue(people[1], out b);

        if (!isAFound && !isBFound)
        {
            friends[people[0]] = ++idx;
            friendSets.Add(-1);
            a = idx;
            setCounter[a] = 1;

            friends[people[1]] = ++idx;
            friendSets.Add(-1);
            b = idx;
            setCounter[b] = 1;
        }
        else if (isAFound && isBFound) { }
        else if (isAFound)
        {
            friends[people[1]] = ++idx;
            friendSets.Add(-1);
            b = idx;
            setCounter[b] = 1;
        }
        else
        {
            friends[people[0]] = ++idx;
            friendSets.Add(-1);
            a = idx;
            setCounter[a] = 1;
        }

        result = UnionSet(friendSets, setCounter, a, b);

        sb.AppendLine(setCounter[result].ToString());
    }

    t--;
}

Console.Write(sb.ToString());

int UnionSet(List<int> elements, Dictionary<int, int> counter, int a, int b)
{
    int aRoot = FindSet(elements, a);
    int bRoot = FindSet(elements, b);

    if (aRoot == bRoot)
        return aRoot;

    if (elements[aRoot] < elements[bRoot])
    {
        elements[bRoot] = aRoot;
        counter[aRoot] += counter[bRoot];
        counter.Remove(bRoot);
        return aRoot;
    }
    else
    {
        if (elements[aRoot] == elements[bRoot])
            --elements[bRoot];
        elements[aRoot] = bRoot;
        counter[bRoot] += counter[aRoot];
        counter.Remove(aRoot);
        return bRoot;
    }
}

int FindSet(List<int> elements, int target)
{
    if (elements.Count <= target) return -1;

    if (elements[target] < 0) return target;
    else return elements[target] = FindSet(elements, elements[target]);
}
