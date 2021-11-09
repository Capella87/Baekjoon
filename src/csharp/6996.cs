// 백준 6996번 문제 : 애너그램
// https://www.acmicpc.net/problem/6996
// 알고리즘 분류 : 구현, 문자열, 정렬

using System;

namespace anagram
{
    public class Anagrams
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                bool isAnagram = true;
                string[] input = Console.ReadLine().Split(' ');
                if (input[0].Length != input[1].Length) isAnagram = false;
                if (isAnagram)
                {
                    int[] aCount = new int[26];
                    int[] bCount = new int[26];
                    for (int j = 0; j < input[0].Length; j++)
                        aCount[input[0][j] - 'a']++;
                    for (int j = 0; j < input[1].Length; j++)
                        bCount[input[1][j] - 'a']++;
                    for (int j = 0; j < 26; j++)
                    {
                        if (aCount[j] != bCount[j])
                        {
                            isAnagram = false;
                            break;
                        }
                    }
                }
                Console.Write($"{input[0]} & {input[1]} are ");
                if (!isAnagram) Console.Write("NOT ");
                Console.WriteLine($"anagrams.");
            }
        }
    }
}