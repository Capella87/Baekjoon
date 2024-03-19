// 백준 14442번 문제 : 벽 부수고 이동하기 2
// https://www.acmicpc.net/problem/14442
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

// cond[0] => n; cond[1] => m; cond[2] => k;
int[] cond = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);

var map = new string[cond[0]];
for (int i = 0; i < cond[0]; i++)
    map[i] = Console.ReadLine();

int[,,] isVisited = new int[cond[0], cond[1], cond[2] + 1];
int[] yMove = { 0, 1, 0, -1 };
int[] xMove = { 1, 0, -1, 0 };

Console.WriteLine(bfs());

int bfs()
{
    int move = 1, breakDownCount = 0, x = 0, y = 0, n_x = 0, n_y = 0;
    var q = new Queue<(int y, int x, int bdCount)>();

    isVisited[0, 0, 0] = 1;
    q.Enqueue((y, x, breakDownCount));

    while (q.Count > 0)
    {
        (y, x, breakDownCount) = q.Dequeue();
        move = isVisited[y, x, breakDownCount];

        if (y == cond[0] - 1 && x == cond[1] - 1) return move;

        for (int i = 0; i < 4; i++)
        {
            n_y = y + yMove[i];
            n_x = x + xMove[i];

            // Skip out of range
            if (n_y < 0 || n_y >= cond[0] || n_x < 0 || n_x >= cond[1]) continue;

            if (map[n_y][n_x] == '0' && isVisited[n_y, n_x, breakDownCount] == 0)
            {
                isVisited[n_y, n_x, breakDownCount] = move + 1;
                q.Enqueue((n_y, n_x, breakDownCount));
            }
            else if (map[n_y][n_x] == '1' && breakDownCount < cond[2] && isVisited[n_y, n_x, breakDownCount + 1] == 0)
            {
                isVisited[n_y, n_x, breakDownCount + 1] = move + 1;
                q.Enqueue((n_y, n_x, breakDownCount + 1));
            }
        }
    }
    return -1;
}
