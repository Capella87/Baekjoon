// 백준 15961번 문제 : 회전 초밥
// https://www.acmicpc.net/problem/15961
// 알고리즘 분류 : 두 포인터, 슬라이딩 윈도우

using System;

namespace Sushi
{
    public static class MainApp
    {
        private static int[] _sushiCount = new int[3001];

        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int d = int.Parse(input[1]);
            int k = int.Parse(input[2]);
            int c = int.Parse(input[3]);

            var conveyor = new int[n];
            for (int i = 0; i < n; i++)
                conveyor[i] = int.Parse(Console.ReadLine());

            int start = 0, end = k - 1, begin = k - 1;
            int sushiStat = 0;
            for (int i = start; i <= end; i++)
            {
                if (_sushiCount[conveyor[i]] == 0)
                    sushiStat++;
                _sushiCount[conveyor[i]]++;
            }
            if (_sushiCount[c] == 0)
                sushiStat++;
            _sushiCount[c]++;
            int max = sushiStat;

            while (true)
            {
                end = (end + 1) % n;
                if (end == begin) break;

                _sushiCount[conveyor[start]]--;
                if (_sushiCount[conveyor[start]] == 0)
                    sushiStat--;
                start = (start + 1) % n;
                if (_sushiCount[conveyor[end]] == 0)
                    sushiStat++;
                _sushiCount[conveyor[end]]++;

                if (max < sushiStat) max = sushiStat;
            }

            Console.WriteLine(max);
        }
    }
}