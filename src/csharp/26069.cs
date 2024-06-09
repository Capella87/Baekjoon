// 백준 26069번 문제 : 붙임성 좋은 총총이
// https://www.acmicpc.net/problem/26069
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

int n = int.Parse(Console.ReadLine());
var dancers = new HashSet<string>();
dancers.Add("ChongChong");
var isHit = new[] { false, false, };

while (n > 0)
{
    var relation = Console.ReadLine().Split();
    isHit[0] = dancers.Contains(relation[0]);
    isHit[1] = dancers.Contains(relation[1]);

    if (isHit[0] && !isHit[1])
        dancers.Add(relation[1]);
    else if (!isHit[0] && isHit[1])
        dancers.Add(relation[0]);
    n--;
}
Console.WriteLine(dancers.Count);
