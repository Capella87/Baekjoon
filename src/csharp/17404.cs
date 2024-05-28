// 백준 17404번 문제 : RGB거리 2
// https://www.acmicpc.net/problem/17404
// 알고리즘 분류 : 다이나믹 프로그래밍

int n = int.Parse(Console.ReadLine());

var cache = new int[n, 3];
var arr = new int[n, 3];
int ans = int.MaxValue;

for (int i = 0; i < n; i++)
{
    var temp = Console.ReadLine().Split();
    for (int j = 0; j < 3; j++)
        arr[i, j] = int.Parse(temp[j]);
}

for (int color = 0; color < 3; color++)
{
    // Pick the first house's color
    for (int i = 0; i < 3; i++)
    {
        if (i == color)
            cache[0, i] = arr[0, i];
        else cache[0, i] = 10_000_000;
    }

    // Calculate whenever the first house and the last house are painted with the same color..
    for (int i = 1; i < n; i++)
    {
        cache[i, 0] = arr[i, 0] + Math.Min(cache[i - 1, 1], cache[i - 1, 2]);
        cache[i, 1] = arr[i, 1] + Math.Min(cache[i - 1, 0], cache[i - 1, 2]);
        cache[i, 2] = arr[i, 2] + Math.Min(cache[i - 1, 0], cache[i - 1, 1]);
    }

    // Exclude the case that selecting the same color for the first and last houses
    // Because cache[i, 0] means the minimum cost of painting the first i houses and the i-th house is painted with the 0-th color
    for (int i = 0; i < 3; i++)
    {
        if (i == color) continue;
        ans = Math.Min(ans, cache[n - 1, i]);
    }
}

Console.WriteLine(ans);
