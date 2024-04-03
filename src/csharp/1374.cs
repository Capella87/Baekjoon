// 백준 1374번 문제 : 강의실
// https://www.acmicpc.net/problem/1374
// 알고리즘 분류 : 자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐

int n = int.Parse(Console.ReadLine());

var pq = new PriorityQueue<int, int>();
var arr = new List<(int, int)>();

for (int i = 0; i < n; i++)
{
    var temp = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);
    arr.Add((temp[1], temp[2]));
}

int time = 0, end, start;
arr.Sort();
for (int i = 0; i < arr.Count; i++)
{
    time = arr[i].Item1;
    if (pq.TryPeek(out start, out end) && time >= end)
    {
        pq.Dequeue();
    }

    pq.Enqueue(arr[i].Item1, arr[i].Item2);
}

Console.WriteLine(pq.Count);
