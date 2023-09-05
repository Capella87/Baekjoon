// 백준 2012번 문제 : 등수 매기기
// https://www.acmicpc.net/problem/2012
// 알고리즘 분류 : 그리디 알고리즘, 정렬

// This source code requires .NET 6 or later.

int n = int.Parse(Console.ReadLine());
long[] arr = new long[n];

for (int i = 0; i < n; i++)
{
    arr[i] = long.Parse(Console.ReadLine());
}
Array.Sort(arr);
long currentMin = 1;
long diffTotal = 0;

for (int i = 0; i < n; i++)
{
    diffTotal += Math.Abs(arr[i] - currentMin++);
}

Console.WriteLine(diffTotal);
