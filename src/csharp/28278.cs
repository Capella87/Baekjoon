// 백준 28278번 문제 : 스택 2
// https://www.acmicpc.net/problem/28278
// 알고리즘 분류 : 자료 구조, 스택

using System.Text;

int n = int.Parse(Console.ReadLine());
int[] parameters;
var sbuilder = new StringBuilder();

var stk = new CapellaStack();

for (int i = 0; i < n; i++)
{
    parameters = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    switch (parameters[0])
    {
        case 1:
            stk.Push(parameters[1]);
            break;
        case 2:
            sbuilder.AppendLine(stk.Pop().ToString());
            break;
        case 3:
            sbuilder.AppendLine(stk.Count.ToString());
            break;
        case 4:
            sbuilder.AppendLine(stk.IsEmpty() ? "1" : "0");
            break;
        case 5:
            sbuilder.AppendLine(stk.Peek().ToString());
            break;
    }
}
Console.Write(sbuilder.ToString());

public class CapellaStack
{
    private readonly int _capacity;
    private int _idx;
    private int _count;
    private int[] _stk;

    public CapellaStack(int capacity = 1_000_000)
    {
        _capacity = capacity;
        _stk = new int[_capacity];
        _count = 0;
        _idx = -1;
    }

    public int Count => _count;

    public void Push(int target)
    {
        if (_count == _capacity)
            return;
        _stk[++_idx] = target;
        _count++;
    }

    public int Peek()
    {
        if (_idx < 0) return -1;
        return _stk[_idx];
    }

    public int Pop()
    {
        if (_idx < 0) return -1;
        int rt = _stk[_idx--];
        _count--;
        return rt;
    }

    public bool IsEmpty()
    {
        return (_idx < 0) ? true : false;
    }
}
