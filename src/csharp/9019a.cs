// 백준 9019번 문제 : DSLR
// https://www.acmicpc.net/problem/14889
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
    var registerArray = new string[10_000];
    for (int i = 0; i < 10_000; i++) registerArray[i] = new string("");
    string currentMove = "";
    int loc;

    var q = new Queue<(int location, string moveStatus)>();
    q.Enqueue((a, currentMove));

    while (q.Count > 0)
    {
        (loc, currentMove) = q.Dequeue();

        if (loc == b) break;

        int newLocation = (loc * 2) % 10_000;
        if (newLocation != a && (registerArray[newLocation].Length == 0 || (currentMove.Length + 1) < registerArray[newLocation].Length))
        {
            registerArray[newLocation] = currentMove + "D";
            q.Enqueue((newLocation, registerArray[newLocation]));
        }

        newLocation = (loc == 0) ? 9_999 : loc - 1;
        if (newLocation != a && (registerArray[newLocation].Length == 0 || (currentMove.Length + 1) < registerArray[newLocation].Length))
        {
            registerArray[newLocation] = currentMove + "S";
            q.Enqueue((newLocation, registerArray[newLocation]));
        }

        newLocation = Shift(loc, true);
        if (newLocation != a && (registerArray[newLocation].Length == 0 || (currentMove.Length + 1) < registerArray[newLocation].Length))
        {
            registerArray[newLocation] = currentMove + "L";
            q.Enqueue((newLocation, registerArray[newLocation]));
        }

        newLocation = Shift(loc, false);
        if (newLocation != a && (registerArray[newLocation].Length == 0 || (currentMove.Length + 1) < registerArray[newLocation].Length))
        {
            registerArray[newLocation] = currentMove + "R";
            q.Enqueue((newLocation, registerArray[newLocation]));
        }
    }

    return Convert.ToString(registerArray[b]);
}

int Shift(int target, bool isLeft)
{
    int result = target;
    var arr = new int[4];
    int idx = 3;

    while (result != 0)
    {
        arr[idx--] = result % 10;
        result /= 10;
    }

    return isLeft ? (arr[0] + (10 * ((10 * ((10 * arr[1]) + arr[2])) + arr[3]))) : ((((((arr[3] * 10) + arr[0]) * 10) + arr[1]) * 10) + arr[2]);
}
