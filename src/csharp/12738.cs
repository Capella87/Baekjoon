// 백준 12738번 문제 : 가장 긴 증가하는 부분 수열 3
// https://www.acmicpc.net/problem/12738
// 알고리즘 분류 : 이분 탐색, 가장 긴 증가하는 부분 수열: o(n log n)

using System;

namespace LIS
{
    public static class Program
    {
        static int[] _arr;
        static int[] _lis;
        static int _lastPos = 0;

        public static int LowerBound(int left, int right, int target) // Returns the index of number which is smaller than target.
        {
            while (left < right)
            {
                int mid = (left + right) / 2;

                if (_lis[mid] < target) left = mid + 1;
                else right = mid;
            }

            return right; // Returns index of end number of binary search range.
        }

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');

            _arr = new int[n];
            _lis = new int[n];
            for (int i = 0; i < n; i++)
                _arr[i] = int.Parse(input[i]);
            _lis[0] = _arr[0];

            for (int i = 1; i < n; i++)
            {
                if (_lis[_lastPos] < _arr[i]) _lis[++_lastPos] = _arr[i]; // Add to lis array if _arr[i] is bigger than any numbers in the array.
                else _lis[LowerBound(0, _lastPos, _arr[i])] = _arr[i]; // Get suitable location by binary search derived algorithm and set to _arr[i].
            }

            Console.WriteLine(_lastPos + 1);
        }
    }
}