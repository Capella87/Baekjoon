// 백준 9019번 문제 : DSLR
// https://www.acmicpc.net/problem/9019
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System.Text;

int n = int.Parse(Console.ReadLine());
var sb = new StringBuilder();

for (int i = 0; i < n; i++)
{
    var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    sb.AppendLine(OperateRegister(conditions[0], conditions[1]));
}

Console.Write(sb.ToString());

string OperateRegister(int a, int b)
{
    var isVisited = new bool[10_000];
    var q = new Queue<(int location, string status)>();
    int loc;
    string stat = "";
    isVisited[a] = true;
    q.Enqueue((a, ""));

    while (q.Count > 0)
    {
        (loc, stat) = q.Dequeue();

        if (loc == b) break;

        int newLocation = (loc * 2) % 10_000;
        if (!isVisited[newLocation])
        {
            q.Enqueue((newLocation, stat + "D"));
            isVisited[newLocation] = true;
        }

        newLocation = loc == 0 ? 9_999 : loc - 1;
        if (!isVisited[newLocation])
        {
            q.Enqueue((newLocation, stat + "S"));
            isVisited[newLocation] = true;
        }

        newLocation = (loc / 1000) + (loc % 1000) * 10;
        if (!isVisited[newLocation])
        {
            q.Enqueue((newLocation, stat + "L"));
            isVisited[newLocation] = true;
        }

        newLocation = (loc / 10) + (loc % 10) * 1000;
        if (!isVisited[newLocation])
        {
            q.Enqueue((newLocation, stat + "R"));
            isVisited[newLocation] = true;
        }
    }

    return stat;
}
