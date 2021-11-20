// 백준 1205번 문제 : 등수 구하기
// https://www.acmicpc.net/problem/1205
// 알고리즘 분류 : 구현

using System;

namespace Rank
{
    public class Rank
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(input[0]);
            int newScore = Convert.ToInt32(input[1]);
            int p = Convert.ToInt32(input[2]);
            
            int newRank = 1;
            int dupCount = 0;
            if (n > 0)
            {
                input = Console.ReadLine().Split(' ');
                for (int i = 0; i < n; i++)
                {
                    int temp = int.Parse(input[i]);
                    if (newScore < temp) newRank++;
                    else if (newScore == temp) dupCount++; 
                }
            }
            Console.WriteLine(newRank + dupCount > p ? "-1" : newRank);
        }
    }
}