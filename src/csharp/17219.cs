// 백준 17219번 문제 : 비밀번호 찾기
// https://www.acmicpc.net/problem/17219
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵

using System;
using System.Collections;
using System.Text;

namespace Password
{
    public static class Program
    {
        public static void Main()
        {
            var saver = new Hashtable();

            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine().Split(' ');
                saver.Add(input[0], input[1]);
            }
            var result = new StringBuilder();
            for (int i = 0; i < m; i++)
            {
                string inpt = Console.ReadLine();
                result.AppendLine(saver[inpt].ToString());
            }
            Console.Write(result.ToString());
        }
    }
}