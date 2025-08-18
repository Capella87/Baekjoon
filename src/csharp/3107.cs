// 백준 3107번 문제 : IPv6
// https://www.acmicpc.net/problem/3107
// 알고리즘 분류 : 구현, 문자열

using System;
using System.Text;

namespace Address
{
    public static class MainApp
    {
        public static void Main()
        {
            string input = Console.ReadLine();
            bool isSegment = false;
            int segmentCount = 0;
            int dColonIdx = -1;
            bool? isFinished = null;
            int i;

            for (i = 0; i <= input.Length; i++)
            {
                if (i == input.Length || input[i] == ':')
                {
                    if (isSegment)
                    {
                        isSegment = false;
                        segmentCount++;
                    }

                    if (i + 1 < input.Length && input[i + 1] == ':')
                    {
                        isFinished = false;
                        dColonIdx = segmentCount;
                        i++;
                    }
                }
                else if (input[i] != ':')
                    isSegment = true;
            }

            string[] addressSegment = input.Split(':', StringSplitOptions.RemoveEmptyEntries);
            var fullAddress = new StringBuilder();
            i = 0;
            do
            {
                if (i == dColonIdx)
                {
                    for (int j = 0; j < 8 - segmentCount; j++)
                    {
                        fullAddress.Append("0000");
                        if (j != 8 - segmentCount - 1) fullAddress.Append(":");
                    }
                    isFinished = true;
                    if (dColonIdx != segmentCount) fullAddress.Append(':');
                    else continue;
                }
                for (int j = 0; j < 4 - addressSegment[i].Length; j++)
                    fullAddress.Append('0');
                fullAddress.Append(addressSegment[i]);
                if (i < segmentCount - 1)
                    fullAddress.Append(':');
                i++;
            } while (i < segmentCount);
            if (isFinished.HasValue && !isFinished.Value)
            {
                fullAddress.Append(':');
                for (int j = 0; j < 8 - segmentCount; j++)
                {
                    fullAddress.Append("0000");
                    if (j != 8 - segmentCount - 1) fullAddress.Append(":");
                }
                if (dColonIdx != segmentCount) fullAddress.Append(':');
            }

            Console.WriteLine(fullAddress.ToString());
        }
    }
}
