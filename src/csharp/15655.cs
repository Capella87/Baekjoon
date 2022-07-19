// 백준 15655번 문제 : N과 M (6)
// https://www.acmicpc.net/problem/15655
// 알고리즘 분류 : 백트래킹

using System;

namespace NM
{
    public static class Program
    {
        static int[] _input;
        static int[] _nums;
        static int[] _result;

        public static void Main()
        {
            _input = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            _nums = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            Array.Sort(_nums);
            _result = new int[_input[1]];

            BackTracking(0, 0);

            void BackTracking(int count, int pos)
            {
                if (count == _input[1])
                {
                    foreach (var c in _result)
                        Console.Write($"{c} ");
                    Console.WriteLine();
                    return;
                }
                else if (pos == _input[0]) return;

                for (int i = pos; i < _input[0]; i++)
                {
                    _result[count] = _nums[i];
                    BackTracking(count + 1, i + 1);
                }
            }
        }
    }
}