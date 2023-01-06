// 백준 24060번 문제 : 알고리즘 수업 - 병합 정렬 1
// https://www.acmicpc.net/problem/24060
// 알고리즘 분류 : 구현, 정렬, 재귀

using System;

namespace MergeSort
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            int[] arr = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            var temp = new int[input[0]];

            Console.WriteLine(GetKthSavedNumber(arr, temp, input[0], input[1]));

            void Merge(int[] arr, int[] temp, ref int savedCount, ref int savedNumber, int left, int right, int mid, int k)
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
                        savedNumber = arr[i];
                        return;
                    }
                    i++;
                    l++;
                }
            }

            void MergeSort(int[] arr, int[] temp, ref int savedCount, ref int savedNumber, int left, int right, int k)
            {
                if (left >= right) return;

                int mid = (left + right) / 2;

                MergeSort(arr, temp, ref savedCount, ref savedNumber, left, mid, k);
                if (savedCount == k) return;
                MergeSort(arr, temp, ref savedCount, ref savedNumber, mid + 1, right, k);
                if (savedCount == k) return;

                Merge(arr, temp, ref savedCount, ref savedNumber, left, right, mid, k);
                if (savedCount == k) return;
            }

            int GetKthSavedNumber(int[] arr, int[] temp, int n, int k)
            {
                int savedCount = 0;
                int savedNumber = -1;

                MergeSort(arr, temp, ref savedCount, ref savedNumber, 0, n - 1, k);

                return savedNumber;
            }
        }
    }
}