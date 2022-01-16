// 백준 1331번 문제 : 나이트 투어
// https://www.acmicpc.net/problem/1331
// 알고리즘 분류 : 구현, 시뮬레이션

using System;

namespace KnightTour
{
    public class KnightTour
    {
        public static void Main()
        {
            bool[,] visitChecker = new bool[6, 6];
            string[] location = new string[36];
            int xDiff, yDiff;

            for (int i = 0; i < 36; i++)
            {
                location[i] = Console.ReadLine();
                visitChecker[Convert.ToInt32(location[i][0] - 'A'), Convert.ToInt32(location[i][1] - '1')] = true;
            }

            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    if (visitChecker[i, j] == false)
                        goto invalid;

            for (int i = 0; i < 35; i++)
            {
                xDiff = Math.Abs(Convert.ToInt32(location[i][0] - location[i + 1][0]));
                yDiff = Math.Abs(Convert.ToInt32(location[i][1] - location[i + 1][1]));

                if ((xDiff == 2 && yDiff == 1) || (xDiff == 1 && yDiff == 2)) // Please refer resource in the webpage
                    continue;
                else goto invalid;
            }

            xDiff = Math.Abs(Convert.ToInt32(location[35][0] - location[0][0]));
            yDiff = Math.Abs(Convert.ToInt32(location[35][1] - location[0][1]));
            if ((xDiff == 2 && yDiff == 1) || (xDiff == 1 && yDiff == 2))
            {
                Console.WriteLine("Valid");
                return;
            }
            else goto invalid;

            invalid:
            Console.WriteLine("Invalid");
        }
    }
}