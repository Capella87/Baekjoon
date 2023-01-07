// 백준 5014번 문제 : 스타트링크
// https://www.acmicpc.net/problem/5014
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System;
using System.Collections.Generic;

namespace StartLink
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);

            // F, S, G, U, D are contained as the input array
            int[,] isVisited = new int[input[0] + 1, 2];

            Console.WriteLine(MoveElevator(isVisited, input[0], input[1], input[2], input[3], input[4]));

            string MoveElevator(int[,] isVisited, int f, int s, int g, int u, int d)
            {
                var queue = new Queue<(int dest, int moveCount)>();
                int move = 0;

                queue.Enqueue((s, 0));
                while (queue.Count > 0)
                {
                    var (dest, moveCount) = queue.Dequeue();
                    int currentFloor = s;

                    currentFloor = dest;
                    move = moveCount;

                    if (currentFloor == g)
                        return Convert.ToString(move);

                    // 위로 올라가려는 층이 있다 -> 일단 올라간다.
                    int nextLoc = currentFloor + u;
                    if (nextLoc <= f && (isVisited[nextLoc, 0] == 0 || (move + 1) < isVisited[nextLoc, 0]))
                    {
                        isVisited[nextLoc, 0] = move + 1;
                        queue.Enqueue((nextLoc, move + 1));
                    }

                    // 아래로 내려가려는 층이 있다 -> 일단 내려간다.
                    nextLoc = currentFloor - d;
                    if (nextLoc >= 1 && (isVisited[nextLoc, 1] == 0 || (move + 1) < isVisited[nextLoc, 1]))
                    {
                        isVisited[nextLoc, 1] = move + 1;
                        queue.Enqueue((nextLoc, move + 1));
                    }
                }

                return "use the stairs";
            }
         }
    }
}