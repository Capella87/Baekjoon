// 백준 2304번 문제 : 창고 다각형
// https://www.acmicpc.net/problem/2304
// 알고리즘 분류 : 자료 구조, 브루트포스 알고리즘, 스택

using System;
using System.Collections.Generic;

namespace Polygon
{
    public class Polygon
    {
        public static void Main()
        {
            var storage = new Stack<(int l, int h)>();

            int n = Convert.ToInt32(Console.ReadLine());
            var pillows = new List<(int l, int h)>();
            for (int i = 0; i < n; i++)
            {
                string[] temp = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
                pillows.Add((Convert.ToInt32(temp[0]), Convert.ToInt32(temp[1])));
            }
            pillows.Sort();
            (int l, int h) max = pillows[0];
            for (int i = 0; i < pillows.Count; i++)
            {
                while (storage.Count > 0 && storage.Peek().h < pillows[i].h && storage.Peek().h < max.h)
                    storage.Pop();
                if (max.h < pillows[i].h)
                    max = pillows[i];
                storage.Push(pillows[i]);
            }

            int area = 0;
            (int l, int h)? current, prev = null;
            while (storage.Count > 0)
            {
                current = storage.Pop();
                if (prev != null)
                {
                    if (current.Value.h >= prev.Value.h)
                        area += (prev.Value.l - current.Value.l - 1) * prev.Value.h;
                    else area += (prev.Value.l - current.Value.l - 1) * current.Value.h;
                }
                area += current.Value.h;
                prev = current;
            }
            Console.WriteLine(area);
        }
    }
}