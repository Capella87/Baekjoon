// 백준 15486번 문제 : 퇴사 2
// https://www.acmicpc.net/problem/15486
// 알고리즘 분류 : 다이나믹 프로그래밍

using System;

namespace Leave
{
    public static class MainApp
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            var day = new int[n + 1];
            var reward = new int[n + 1];
            int max = 0;

            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                day[i] = int.Parse(input[0]);
                reward[i] = int.Parse(input[1]);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (i + day[i] > n) // 처리 완료일자가 퇴사 후 시점인 경우
                    reward[i] = reward[i + 1]; // 중간에 이런 경우가 있는 경우 이 경우 뒤에서 퇴사 전 시점에 완료되는 경우에서의 최댓값이 손실되는 것을 방지
                else
                    reward[i] = Math.Max(reward[i] + reward[i + day[i]], reward[i + 1]); // 현재 일을 고르는 경우 및 다음날에 고르는 경우를 비교
                if (max < reward[i]) max = reward[i];
            }
            Console.WriteLine(max);
        }
    }
}