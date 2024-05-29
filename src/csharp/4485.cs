// 백준 4485번 문제 : 녹색 옷 입은 애가 젤다지?
// https://www.acmicpc.net/problem/4485
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 데이크스트라, 최단 경로

using System.Text;

public static class Program
{
    public static readonly int[] yMove = { 0, 1, 0, -1 };
    public static readonly int[] xMove = { 1, 0, -1, 0 };

    public static void Main()
    {
        var sb = new StringBuilder();
        int n, k = 1;

        while (true)
        {
            n = int.Parse(Console.ReadLine());
            if (n == 0) break;

            var board = new int[n, n];
            var minRupoors = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                var temp = Console.ReadLine().Split();
                for (int j = 0; j < n; j++)
                {
                    board[i, j] = int.Parse(temp[j]);
                    minRupoors[i, j] = int.MaxValue;
                }
            }
            minRupoors[0, 0] = board[0, 0];

            sb.AppendLine($"Problem {k++}: {GetMinimumRupoors(board, minRupoors, n)}");
        }

        Console.Write(sb.ToString());
    }

    public static int GetMinimumRupoors(int[,] board, int[,] minRupoors, int n)
    {
        var pq = new PriorityQueue<(int, int), int>();
        int y = 0, x = 0, cr;

        pq.Enqueue((0, 0), board[0, 0]);
        while (pq.Count > 0)
        {
            pq.TryDequeue(out var t, out cr);
            (y, x) = t;

            // Just exit when reaching to [n - 1, n - 1].
            if (y == n - 1 && x == n - 1)
                break;

            for (int i = 0; i < 4; i++)
            {
                int newY = y + yMove[i];
                int newX = x + xMove[i];

                if (newY >= n || newX >= n || newY < 0 || newX < 0)
                    continue;
                int rupoors = cr + board[newY, newX];

                if (rupoors < minRupoors[newY, newX])
                {
                    minRupoors[newY, newX] = rupoors;
                    pq.Enqueue((newY, newX), rupoors);
                }
            }
        }

        return minRupoors[n - 1, n - 1];
    }
}
