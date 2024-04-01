// 백준 2295번 문제 : 세 수의 합
// https://www.acmicpc.net/problem/2295
// 알고리즘 분류 : 자료 구조, 이분 탐색, 해시를 사용한 집합과 맵, 중간에서 만나기

int n = int.Parse(Console.ReadLine());
var arr = new int[n];

for (int i = 0; i < n; i++)
    arr[i] = int.Parse(Console.ReadLine());
var twoArr = new int[n * n];
Array.Sort(arr);
int cIdx = 0, temp, result;

for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        twoArr[cIdx++] = arr[i] + arr[j];
Array.Sort(twoArr);

for (int i = n - 1; i > 0; i--)
{
    for (int j = 0; j < i; j++)
    {
        temp = arr[i] - arr[j];
        result = BinarySearch(twoArr, temp, 0, twoArr.Length - 1);
        if (result != -1)
        {
            Console.WriteLine(arr[i]);
            return;
        }
    }
}

int BinarySearch(int[] arr, int target, int left, int right)
{
    int mid;
    if (left >= arr.Length) return -1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
