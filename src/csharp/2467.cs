// 백준 2467번 문제 : 두 용액
// https://www.acmicpc.net/problem/2467
// 알고리즘 분류 : 이분 탐색, 두 포인터

int n = int.Parse(Console.ReadLine());
var solutions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
int left = 0, right = n - 1;
int minSum = int.MaxValue, minLeft = 0, minRight = 0;

while (left < right)
{
    int sum = Math.Abs(solutions[left] + solutions[right]);
    if (sum < minSum)
    {
        minSum = sum;
        minLeft = solutions[left];
        minRight = solutions[right];
    }
    if (sum == 0) break;
    if (Math.Abs(solutions[left]) > Math.Abs(solutions[right])) left++;
    else right--;
}
Console.WriteLine($"{minLeft} {minRight}");
