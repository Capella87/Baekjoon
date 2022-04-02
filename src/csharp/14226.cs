// 백준 14226번 문제 : 이모티콘
// https://www.acmicpc.net/problem/14226
// 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System;
using System.Collections.Generic;

namespace Emoticon
{
    public static class MainApp
    {
        public static void Main()
        {
            int s = int.Parse(Console.ReadLine());
            var isVisited = new bool[2001, 2001];
            var q = new Queue<(int, int, int)>();

            int current = 1, clipboard = 0, time = 0, min = 10000;
            isVisited[1, 0] = true;
            q.Enqueue((current, clipboard, time));

            while (q.Count > 0)
            {
                (current, clipboard, time) = q.Dequeue();
                
                if (current == s && time < min)
                {
                    min = time;
                    continue;
                }

                if (current < s) // 클립보드 복사
                {
                    if (!isVisited[current, current])
                    {
                        isVisited[current, current] = true;
                        q.Enqueue((current, current, time + 1));
                    }
                }
                
                if (clipboard > 0 && current < s) // 붙여넣기
                {
                    if (!isVisited[current + clipboard, clipboard])
                    {
                        isVisited[current + clipboard, clipboard] = true;
                        q.Enqueue((current + clipboard, clipboard, time + 1));
                    }
                }

                if (current > 1) // 이모티콘 하나 삭제
                {
                    if (!isVisited[current - 1, clipboard])
                    {
                        isVisited[current - 1, clipboard] = true;
                        q.Enqueue((current - 1, clipboard, time + 1));
                    }
                }
            }
            Console.WriteLine(min);
        }
    }
}