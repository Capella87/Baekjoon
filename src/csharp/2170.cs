// 백준 2170번 문제 : 선 긋기
// https://www.acmicpc.net/problem/2170
// 알고리즘 분류 : 정렬, 스위핑

// Greedy Algorithm

int n = int.Parse(Console.ReadLine());
var pq = new PriorityQueue<(int, int), int>();

for (int i = 0; i < n; i++)
{
    var r = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

    pq.Enqueue((r[0], r[1]), r[0]);
}

int curStart = int.MinValue;
int curEnd = int.MinValue;
long total = 0;

while (pq.Count > 0)
{
    var (start, end) = pq.Dequeue();

    if (curEnd < start)
    {
        total += curEnd - curStart;
        curStart = start;
        curEnd = end;
        continue;
    }
    curEnd = (curEnd < end) ? end : curEnd;
}
total += curEnd - curStart;

Console.WriteLine(total);
