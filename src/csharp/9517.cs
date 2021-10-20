// 백준 9517번 문제 : 아이 러브 크로아티아
// https://www.acmicpc.net/problem/9517
// 알고리즘 분류 : 구현, 시뮬레이션

using System;

namespace croatia
{
    public class Croatia
    {
        public const int bombTime = 210;

        public static void Main()
        {
            int k = Convert.ToInt32(Console.ReadLine());
            int n = Convert.ToInt32(Console.ReadLine());
            int time = 0, who = k;
            bool flag = false;
            for (var i = 0; i < n; i++)
            {
                string[] str = Console.ReadLine().Split();
                time += Convert.ToInt32(str[0]);
                if (time >= bombTime && !flag)
                {
                    who = k;
                    flag = true;
                }
                if (str[1] == "T") k = k % 8 + 1;
            }
            Console.WriteLine(who);
        }
    }
}