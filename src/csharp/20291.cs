// 백준 20291번 문제 : 파일 정리
// https://www.acmicpc.net/problem/20291
// 알고리즘 분류 : 자료 구조, 문자열, 정렬, 해시를 사용한 집합과 맵, 파싱

using System.Text;

int n = int.Parse(Console.ReadLine());
var extensions = new Dictionary<string, int>();
var sb = new StringBuilder();
for (int i = 0; i < n; i++)
{
    var ext = Console.ReadLine().Split('.')[^1];
    if (!extensions.TryAdd(ext, 1)) extensions[ext]++;
}
var keys = extensions.Keys.ToList();
keys.Sort();
foreach (var key in keys)
    sb.AppendLine($"{key} {extensions[key]}");
Console.Write(sb.ToString());
