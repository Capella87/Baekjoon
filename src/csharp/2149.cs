// 백준 2149번 문제 : 암호 해독
// https://www.acmicpc.net/problem/2149
// 알고리즘 분류 : 구현, 문자열, 정렬

using System;
using System.Collections.Generic;
using System.Linq;

namespace Decryption
{
    public class Comparer : IComparer<(string, int)>
    {
        public int Compare((string, int)a, (string, int)b)
        {
            return a.Item2 - b.Item2;
        }
    }

    public static class MainApp
    {
        public static void Main()
        {
            string key = Console.ReadLine();
            string sortedKey = String.Concat(key.OrderBy(c => c));
            string encrypted = Console.ReadLine();
            var arrList = new List<(string, int)>();
            int row = encrypted.Length / key.Length;
            string[] strArr = new string[key.Length];

            for (int i = 0; i < key.Length; i++)
            {
                strArr[i] += sortedKey[i];
                for (int j = 0; j < row; j++)
                    strArr[i] += encrypted[i * row + j];
            }

            int[] beginArr = new int[26];
            for (int i = 0; i < key.Length; i++)
            {
                int loc = key.IndexOf(strArr[i][0], beginArr[strArr[i][0] - 'A']);
                arrList.Add((strArr[i], loc));
                beginArr[strArr[i][0] - 'A'] = loc + 1;
            }
            arrList.Sort(new Comparer());
            for (int i = 0; i < row; i++)
                for (int j = 0; j < arrList.Count; j++)
                    Console.Write(arrList[j].Item1[i + 1]);
            Console.WriteLine();
        }
    }
}