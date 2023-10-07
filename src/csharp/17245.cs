// 백준 17245번 문제 : 서버실
// https://www.acmicpc.net/problem/17245
// 알고리즘 분류 : 이분 탐색

using System;
using System.Collections;

namespace server
{
    public class Server
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            long total = 0;
            long[] floorCount = new long[10_000_001];
            for (int i = 0; i < n; i++)
            {
                string[] temp = Console.ReadLine().Split(' ');
                for (int j = 0; j < n; j++)
                {
                    long count = Convert.ToInt64(temp[j]);
                    total += count;
                    floorCount[count]++;
                }
            }
            long clusterCount = (long)(n * n) - floorCount[0];
            long onCount = 0, minute = 0;
            int idx = 1;
            while (true)
            {
                if (clusterCount == 0) break;
                onCount += clusterCount;
                clusterCount -= floorCount[idx++]; // 
                minute++;
                if ((double)onCount / (double)total * 100 >= 50) break;
            }
            Console.WriteLine(minute);
        }
    }
}