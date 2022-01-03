// 백준 5464번 문제 : 주차장
// https://www.acmicpc.net/problem/5464
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 큐

using System;
using System.Collections.Generic;

namespace ParkingLot
{
    public class ParkingLot
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            int cCount = m * 2;

            var parkingLot = new Dictionary<int, int>();
            var q = new Queue<int>();

            int[] unitFare = new int[n];
            bool[] slot = new bool[n];
            int[] cars = new int[m];
            int lowVacantNum = 0, total = 0, command;

            for (int i = 0; i < n; i++)
                unitFare[i] = int.Parse(Console.ReadLine());
            for (int i = 0; i < m; i++)
                cars[i] = int.Parse(Console.ReadLine());
            for (int i = 0; i < cCount; i++)
            {
                command = int.Parse(Console.ReadLine());
                if (command > 0)
                {
                    if (parkingLot.Count < n)
                    {
                        parkingLot.Add(command, lowVacantNum);
                        slot[lowVacantNum] = true;
                        while (lowVacantNum < n && slot[lowVacantNum])
                            lowVacantNum++;
                    }
                    else
                        q.Enqueue(command);
                }
                else
                {
                    command = Math.Abs(command);
                    int idx = parkingLot[command];
                    slot[idx] = false;

                    total += cars[command - 1] * unitFare[idx];
                    if (parkingLot.Count == n || lowVacantNum > idx) lowVacantNum = idx;
                    parkingLot.Remove(command);

                    if (q.Count > 0)
                    {
                        parkingLot.Add(q.Dequeue(), lowVacantNum);
                        slot[lowVacantNum] = true;
                        while (lowVacantNum < n && slot[lowVacantNum])
                            lowVacantNum++;
                    }
                }
            }
            Console.WriteLine(total);
        }
    }
}