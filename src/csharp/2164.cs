// 백준 2164번 문제 : 카드2
// https://www.acmicpc.net/problem/2164
// 알고리즘 분류 : 자료 구조, 큐

using System;
using System.Collections.Generic;

namespace card
{
    class Card
    {
        public static void Main()
        {
            Queue<int> deck = new Queue<int>();
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 1; i <= n; i++)
                deck.Enqueue(i);
            while (deck.Count > 1)
            {
                deck.Dequeue();
                deck.Enqueue(deck.Dequeue());
            }
            Console.WriteLine($"{deck.Peek()}");
        }
    }
}