// 백준 2240번 문제 : 자두나무
// https://www.acmicpc.net/problem/2240
// 알고리즘 분류 : 다이나믹 프로그래밍

using System;

namespace Prune
{
    public static class Program
    {
        public static void Main()
        {
            var a = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            var arr = new int[a[0]];
            var cache = new int[a[1] + 1];

            for (int i = 0; i < a[0]; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
                bool isOne = (a[1] % 2 == 0) ? true : false;
                for (int j = 0; j < a[1]; j++)
                {
                    if (i + j < a[1] - 1)
                    {
                        isOne = !isOne;
                        continue;
                    }

                    int nonchange = cache[j];
                    int change = cache[j + 1];

                    nonchange = ((!isOne && arr[i] == 2) || (isOne && arr[i] == 1)) ? nonchange + 1 : nonchange;
                    change = ((!isOne && arr[i] == 2) || (isOne && arr[i] == 1)) ? change + 1 : change;

                    cache[j] = Math.Max(nonchange, change);
                    isOne = !isOne;
                }
                if (arr[i] == 1) cache[a[1]]++;
            }

            int result = 0;
            foreach (var i in cache)
                result = Math.Max(result, i);

            Console.WriteLine(result);
        }
    }
}