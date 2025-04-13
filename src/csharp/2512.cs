// 백준 2512번 문제 : 예산
// https://www.acmicpc.net/problem/2512
// 알고리즘 분류 : 이분 탐색, 매개 변수 탐색

int n = int.Parse(Console.ReadLine());

var arr = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
int m = int.Parse(Console.ReadLine());

Array.Sort(arr);

int result = 0, target = 0;
int leftover = m, idx = 0;
int c = n;
int left = 0, right = n - 1;

while (idx >= left && idx <= right)
{
    target = leftover / (right - left + 1);
    if (target >= arr[right])
    {
        target = arr[right];
        break;
    }
    idx = LowerBound(arr, left, right, target);
    for (int i = left; i < idx; i++)
    {
        leftover -= arr[i];
    }
    if (idx == left) break;
    left = idx;
}
Console.WriteLine(target);

int LowerBound(int[] arr, int left, int right, int target)
{
    int idx = 0;

    while (left <= right)
    {
        idx = (left + right) / 2;
        if (arr[idx] <= target) left = idx + 1;
        else right = idx - 1;
    }

    return left;
}
