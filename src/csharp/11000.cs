// 백준 11000번 문제 : 강의실 배정
// https://www.acmicpc.net/problem/11000
// 알고리즘 분류 : 자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐

using System;
using System.Collections.Generic;

namespace Classroom
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var startQueue = new PriorityQueue<(int, int), int>();
            var endQueue = new PriorityQueue<(int, int), int>();

            for (int i = 0; i < n; i++)
            {
                var schedule = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
                var scheduleInfo = (schedule[0], schedule[1]);

                startQueue.Enqueue(scheduleInfo, schedule[0]);
            }

            int classCount = 0, available = 0;
            int currentTime = 0;
            for (int i = 0; i < n; i++)
            {
                var sInfo = startQueue.Dequeue();
                currentTime = sInfo.Item1;

                while (endQueue.Count > 0 && endQueue.Peek().Item2 <= currentTime)
                {
                    endQueue.Dequeue();
                    available++;
                }

                if (available > 0) available--;
                else classCount++;
                endQueue.Enqueue(sInfo, sInfo.Item2);
            }

            Console.WriteLine(classCount);
        }
    }
}