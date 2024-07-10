// 백준 3015번 문제 : 오아시스 재결합
// https://www.acmicpc.net/problem/3015
// 알고리즘 분류 : 자료 구조, 스택

int n = int.Parse(Console.ReadLine()!);
long visiblePairs = 0;
var oasisFanStk = new Stack<Person>();
int mx = -1;

while (n-- > 0)
{
    var temp = int.Parse(Console.ReadLine()!);
    while (oasisFanStk.Count > 0 && oasisFanStk.Peek().Value < temp)
    {
        var t = oasisFanStk.Pop();
        visiblePairs += t.Count;
    }
    if (oasisFanStk.Count > 0)
    {
        var pk = oasisFanStk.Peek();
        if (pk.Value == temp)
        {
            visiblePairs += pk.Count + ((pk.Value != mx) ? 1 : 0);
            pk.Count++;
            continue;
        }
        visiblePairs++;
    }
    else mx = -1;
    oasisFanStk.Push(new Person(temp));
    mx = Math.Max(mx, temp);
}
Console.WriteLine(visiblePairs);

public class Person
{
    public int Count { get; set; }
    public int Value { get; init; }

    public Person(int value)
    {
        Value = value;
        Count = 1;
    }
}
