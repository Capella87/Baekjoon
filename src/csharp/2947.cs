// 백준 2947번 문제 : 나무 조각
// https://www.acmicpc.net/problem/2947
// 알고리즘 분류 : 구현, 시뮬레이션

using System;

namespace Fragment
{
    class Fragment
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            int[] arr = new int[5];
            for (int i = 0; i < 5; i++) arr[i] = Convert.ToInt32(input[i]);

            bool isChange = false;
            do
            {
                isChange = false;
                for (int i = 0; i < 4; i++)
                {
                    if (arr[i] > arr[i + 1])
                    {
                        Swap(ref arr, i, i + 1);
                        isChange = true;
                    }
                }
            } while (isChange);


            void Swap(ref int[] arr, int a, int b)
            {
                int temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
                for (int i = 0; i < 5; i++) Console.Write($"{arr[i]} ");
                Console.WriteLine();
            }
        }
    }
}