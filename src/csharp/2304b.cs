// 백준 2304번 문제 : 창고 다각형
// https://www.acmicpc.net/problem/2304
// 알고리즘 분류 : 자료 구조, 브루트포스 알고리즘, 스택

// Solution without stack (using counting sort)

using System;

namespace Polygon
{
    public class Storage
    {
        public static void Main()
        {
            int[] arr = new int[1001]; // counting sort
            int n = Convert.ToInt32(Console.ReadLine());

            (int l, int h) max = (0, 0);
            for (int i = 0; i < n; i++)
            {
                string[] temp = Console.ReadLine().Split(' ');
                int idx = int.Parse(temp[0]);
                int height = int.Parse(temp[1]);
                if (max.h < height)
                    max = (idx, height);
                arr[idx] = height;
            }

            int area = 0;
            int partMax = 0;
            for (int i = 1; i < max.l; i++)
            {
                if (arr[i] > 0)
                    partMax = GetMax(partMax, arr[i]);
                area += partMax;
            }
            area += max.h;
            partMax = 0;
            for (int i = 1000; i > max.l; i--)
            {
                if (arr[i] > 0)
                    partMax = GetMax(partMax, arr[i]);
                area += partMax;
            }
            
            Console.WriteLine(area);

            int GetMax(int a, int b)
            {
                return a > b ? a : b;
            }
        }
    }
}