// 백준 5555번 문제 : 반지
// https://www.acmicpc.net/problem/5555
// 알고리즘 분류 : 문자열, 브루트포스 알고리즘

using System;

namespace Ring
{
    class Ring
    {
        public static void Main()
        {
            string keyword = Console.ReadLine();
            int n = Convert.ToInt32(Console.ReadLine());
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                string target = Console.ReadLine();
                bool isAlready = false;
                for (int j = 0; j <= target.Length - keyword.Length; j++)
                {
                    if (target.Substring(j, keyword.Length) == keyword)
                    {
                        count++;
                        isAlready = true;
                        break;
                    }
                }
                if (isAlready) continue;
                for (int j = target.Length - keyword.Length + 1, k = 1; j < target.Length; j++, k++)
                {
                    int len = keyword.Length - k;
                    if (target.Substring(j, len) == keyword.Substring(0, len) && target.Substring(0, k) == keyword.Substring(len))
                    {
                        count++;
                        break;
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}