// 백준 1384번 문제 : 메시지
// https://www.acmicpc.net/problem/1384
// 알고리즘 분류 : 구현

using System;

namespace message
{
    class Message
    {
        public static void processMessage(string[] people, char[][] status, int n)
        {
            bool hasNegative = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (status[i][j] == 'N')
                    {
                        int idx = (i - j - 1) < 0 ? n - 1 - j + i : i - j - 1;
                        Console.WriteLine($"{people[idx]} was nasty about {people[i]}");
                        hasNegative = true;
                    }
                }
            }
            if (hasNegative == false)
                Console.WriteLine("Nobody was nasty");
            Console.WriteLine();
        }

        static void Main()
        {
            int count = 0;
            while (true)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                if (n == 0) break;
                string[] people = new string[n];
                char[][] status = new char[n][];
                for (int i = 0; i < n; i++)
                {
                    string[] input = Console.ReadLine().Split();
                    people[i] = input[0];
                    status[i] = new char[n - 1];
                    for (int j = 0; j < n - 1; j++)
                        status[i][j] = Convert.ToChar(input[j + 1]);
                }
                Console.WriteLine($"Group {++count}");
                processMessage(people, status, n);
            }
        }
    }
}