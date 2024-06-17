// 백준 2098번 문제 : 외판원 순회
// https://www.acmicpc.net/problem/2098
// 알고리즘 분류 : 다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍, 외판원 순회 문제

const int INF = 100_000_000;

int n = int.Parse(Console.ReadLine());
var paths = new List<int[]>();

// Bitwise operation: e.g. 1 << 3 => 1 => 1000(2) => decimal 8; 7 => 111
int allVisitedMark = (1 << n) - 1;
var cache = new List<int[]>();

for (int i = 0; i < n; i++)
{
    paths.Add(Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse));
    var arr = new int[allVisitedMark];
    Array.Fill(arr, -1);
    cache.Add(arr);
}
Console.WriteLine(SalesmanTravel(1, 0));

int SalesmanTravel(int visitStatus, int city)
{
    // If the salesman visited all cities
    if (visitStatus == allVisitedMark)
    {
        return paths[city][0] == 0 ? INF : paths[city][0];
    }

    // Return a cached result if he already visited the city as the array visitStatus shows
    if (cache[city][visitStatus] != -1)
        return cache[city][visitStatus];

    // Marks the city as visited
    cache[city][visitStatus] = INF;
    
    for (int i = 0; i < n; i++)
    {
        if ((visitStatus & (1 << i)) == 0 && paths[city][i] != 0)
        {
            cache[city][visitStatus] = Math.Min(cache[city][visitStatus],
                paths[city][i] + SalesmanTravel(visitStatus | (1 << i), i));
        }
    }
    return cache[city][visitStatus];
}
