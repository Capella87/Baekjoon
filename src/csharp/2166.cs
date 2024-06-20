// 백준 2166번 문제 : 다각형의 면적
// https://www.acmicpc.net/problem/2166
// 알고리즘 분류 : 기하학, 다각형의 넓이

int n = int.Parse(Console.ReadLine());
var l = new List<long[]>();
double sum = 0;

for (int i = 0; i < n; i++)
    l.Add(Array.ConvertAll<string, long>(Console.ReadLine().Split(), long.Parse));
for (int i = 0; i < n - 1; i++)
    sum += (l[i][0] + l[i + 1][0]) * (l[i][1] - l[i + 1][1]);
sum += (l[n - 1][0] + l[0][0]) * (l[n - 1][1] - l[0][1]);
sum = Math.Abs(sum);
sum /= 2;
Console.WriteLine($"{sum:F1}");
