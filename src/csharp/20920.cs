// 백준 20920번 문제 : 영단어 암기는 괴로워
// https://www.acmicpc.net/problem/20920
// 알고리즘 분류 : 자료 구조, 문자열, 정렬, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

using System.Text;

// conditions[0] = n, conditions[1] = m
var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
var d = new Dictionary<string, int>();
var l = new List<string>();

for (int i = 0; i < conditions[0]; i++)
{
    string temp = Console.ReadLine();
    if (temp.Length < conditions[1])
        continue;
    if (!d.TryAdd(temp, 1)) ++d[temp];
    else l.Add(temp);
}

l.Sort((x, y) =>
{
    int xC = d[x], yC = d[y];
    if (xC > yC)
        return -1;
    else if (xC < yC)
        return 1;

    if (x.Length > y.Length)
        return -1;
    else if (x.Length < y.Length)
        return 1;

    return x.CompareTo(y);
});

var sb = new StringBuilder();
for (int i = 0; i < l.Count; i++)
    sb.AppendLine(l[i]);

Console.Write(sb.ToString());
