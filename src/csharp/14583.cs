// 백준 14583번 문제 : 이음줄
// https://www.acmicpc.net/problem/14583
// 알고리즘 분류 : 수학, 기하학

var conditions = Array.ConvertAll<string, double>(Console.ReadLine().Split(' '), double.Parse);

double diagonal = Math.Sqrt(Math.Pow(conditions[0], 2) + Math.Pow(conditions[1], 2));
double a = conditions[1] * (conditions[0] / (conditions[0] + diagonal));
double b = conditions[1] * (diagonal / (conditions[0] + diagonal));
double c = Math.Sqrt(Math.Pow(a, 2.0) + Math.Pow(conditions[0], 2));
double garo = c / 2;
double sero = b * conditions[0] / c;

Console.WriteLine($"{garo:F2} {sero:F2}");
