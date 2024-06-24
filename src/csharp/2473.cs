// 백준 2473번 문제 : 세 용액
// https://www.acmicpc.net/problem/2473
// 알고리즘 분류 : 정렬, 이분 탐색, 두 포인터

int n = int.Parse(Console.ReadLine());
var solutions = Array.ConvertAll<string, long>(Console.ReadLine().Split(), long.Parse);

int start, end;
long mn = long.MaxValue;
int mnStartIdx = 1, mnEndIdx = n - 1, mnIIdx = 0;

Array.Sort(solutions);
for (int i = 0; i < n - 2; i++)
{
    start = i + 1;
    end = n - 1;
    while (start < end)
    {
        long total = solutions[i] + solutions[start] + solutions[end];
        long absTotal = Math.Abs(total);
        if (absTotal < mn)
        {
            mn = absTotal;
            mnStartIdx = start;
            mnEndIdx = end;
            mnIIdx = i;
        }

        if (total < 0) start++;
        else end--;
    }
}
Console.WriteLine($"{solutions[mnIIdx]} {solutions[mnStartIdx]} {solutions[mnEndIdx]}");
