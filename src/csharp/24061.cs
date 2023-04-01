// 백준 24061번 문제 : 알고리즘 수업 - 병합 정렬 2
// https://www.acmicpc.net/problem/24061
// 알고리즘 분류 : 구현, 정렬

// I wonder why this code shows poor performance?

using System;
using System.Text;

namespace MergeSort
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            int[] arr = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            var temp = new int[input[0]];

            i
            GetKthSavedArray(arr, temp, input[0], input[1]);

            void Merge(int[] arr, int[] temp, ref int savedCount, int left, int right, int mid, int k)
            {
                int i = left, j = mid + 1, l = 0;

                while (i <= mid && j <= right)
                {
                    if (arr[i] <= arr[j]) temp[l++] = arr[i++];
                    else temp[l++] = arr[j++];
                }
                while (i <= mid)
                    temp[l++] = arr[i++];
                while (j <= right)
                    temp[l++] = arr[j++];

                i = left;
                l = 0;
                while (i <= right)
                {
                    arr[i] = temp[l];

                    if (++savedCount == k)
                    {
                        var result = new StringBuilder();
                        foreach (int elem in arr)
                            result.Append($"{elem} ");
                        Console.WriteLine(result.ToString());
                        return;
                    }
                    i++;
                    l++;
                }
            }

            void MergeSort(int[] arr, int[] temp, ref int savedCount, int left, int right, int k)
            {
                if (left >= right) return;

                int mid = (left + right) / 2;

                MergeSort(arr, temp, ref savedCount, left, mid, k);
                if (savedCount == k) return;
                MergeSort(arr, temp, ref savedCount, mid + 1, right, k);
                if (savedCount == k) return;

                Merge(arr, temp, ref savedCount, left, right, mid, k);
                if (savedCount == k) return;
            }

            void GetKthSavedArray(int[] arr, int[] temp, int n, int k)
            {
                int savedCount = 0;

                MergeSort(arr, temp, ref savedCount, 0, n - 1, k);
                if (savedCount < k)
                {
                    Console.WriteLine("-1");
                    return;
                }
            }
        }
    }
}