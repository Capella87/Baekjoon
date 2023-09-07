// 백준 25192번 문제 : 인사성 밝은 곰곰이
// https://www.acmicpc.net/problem/25192
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

// This code requires .NET 6 or later

const string enter = "ENTER";
int n = int.Parse(Console.ReadLine());
n--;

int gomTiconCount = 0;
var chatUsers = new HashSet<string>();
Console.ReadLine();

for (int i = 0; i < n; i++)
{
    var input = Console.ReadLine();
    if (input!.Equals(enter))
    {
        chatUsers.Clear();
        continue;
    }

    if (!chatUsers.Contains(input))
    {
        chatUsers.Add(input);
        gomTiconCount++;
    }
}

Console.WriteLine(gomTiconCount);
