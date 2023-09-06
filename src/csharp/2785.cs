// 백준 2785번 문제 : 체인
// https://www.acmicpc.net/problem/2785
// 알고리즘 분류 : 그리디 알고리즘, 정렬

int n = int.Parse(Console.ReadLine());

int[] arr = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);

Array.Sort(arr);

int intervalCount = arr.Length - 1;
int idx = 0;
int result = 0;

while (arr[idx] < intervalCount)
{
    result += arr[idx];
    intervalCount = --intervalCount - arr[idx++];
}

Console.WriteLine(result + intervalCount);
