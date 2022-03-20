// 백준 1620번 문제 : 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵

using System;
using System.Collections.Generic;
using System.Text;

namespace Pokemon
{
    public static class MainApp
    {
        public static void Main()
        {
            var dogam = new Dictionary<string, string>();
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            var sb = new StringBuilder(); // Use StringBuilder for faster output

            string target = "";
            for (int i = 0; i < n; i++)
            {
                target = Console.ReadLine();
                dogam.Add(Convert.ToString(i + 1), target);
                dogam.Add(target, Convert.ToString(i + 1));
            }
            for (int i = 0; i < m; i++)
            {
                target = Console.ReadLine();
                sb.AppendLine(dogam[target]); // Add string and newline.
            }
            Console.WriteLine(sb.ToString()); // Print output in one time.
        }
    }
}