// 백준 2752번 문제 : 세수정렬
// https://www.acmicpc.net/problem/2752
// 알고리즘 분류 : 정렬

using System;

namespace sorting
{
    class Sorting
    {
        static void Main()
        {
            string[] input = Console.ReadLine().Split();
            int[] arr = new int[3];
            for (int i = 0; i < 3; i++)
                arr[i] = Int32.Parse(input[i]);
            for (int i = 0; i < 2; i++) // Selection Sort
            {
                int min = i;
                for (int j = i + 1; j < 3; j++)
                    if (arr[min] > arr[j]) min = j;
                if (min != i)
                {
                    int temp = arr[min];
                    arr[min] = arr[i];
                    arr[i] = temp;
                }
            }
            foreach (var elem in arr)
                Console.Write($"{elem} ");
            Console.WriteLine();
        }
    }
}