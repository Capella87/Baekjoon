// 백준 7562번 문제 : 나이트의 이동
// https://www.acmicpc.net/problem/7562
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System.Text;

var yMove = new[] { -1, 1, 2, 2, 1, -1, -2, -2 };
var xMove = new[] { 2, 2, 1, -1, -2, -2, -1, 1 };

var sb = new StringBuilder();
int n = int.Parse(Console.ReadLine());

while (n > 0)
{
    int i = int.Parse(Console.ReadLine());
    var departure = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    var arrival = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

    sb.Append($"{GetMinimalMove(i, departure, arrival)}\n");
    n--;
}
Console.Write(sb.ToString());

int GetMinimalMove(int i, int[] departure, int[] arrival)
{
    var isVisited = new bool[i, i];
    int y = departure[0], x = departure[1], move = 0;
    var q = new Queue<(int y, int x, int moves)>();
    isVisited[y, x] = true;
    q.Enqueue((y, x, 0));

    while (q.Count > 0)
    {
        (y, x, move) = q.Dequeue();
        if (y == arrival[0] && x == arrival[1])
            break;

        for (int j = 0; j < 8; j++)
        {
            int newY = y + yMove[j];
            int newX = x + xMove[j];
            if (newX < 0 || newY < 0 || newX >= i || newY >= i) continue;

            if (!isVisited[newY, newX])
            {
                isVisited[newY, newX] = true;
                q.Enqueue((newY, newX, move + 1));
            }
        }
    }
    return move;
}
