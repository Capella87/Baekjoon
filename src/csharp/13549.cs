// 백준 13549번 문제 : 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 데이크스트라, 최단 경로, 0-1 너비 우선 탐색

// Dijkstra's Algorithm

var conditions = Array.ConvertAll<string, int>(Console.ReadLine().Split(), int.Parse);

var shortestMove = new int[100_001];
Array.Fill(shortestMove, int.MaxValue);
var q = new PriorityQueue<int, int>();
shortestMove[conditions[0]] = 0;
q.Enqueue(conditions[0], 0);
int location = 0, move = 0, futureLocation;

while (q.Count > 0)
{
    q.TryDequeue(out location, out move);

    futureLocation = location + 1;
    if (futureLocation < 100_001 && location < conditions[1] && (move + 1) < shortestMove[futureLocation])
    {
        q.Enqueue(futureLocation, move + 1);
        shortestMove[futureLocation] = move + 1;
    }

    futureLocation = location - 1;
    if (futureLocation >= 0 && (move + 1) < shortestMove[futureLocation])
    {
        q.Enqueue(futureLocation, move + 1);
        shortestMove[futureLocation] = move + 1;
    }

    futureLocation = location * 2;
    if (futureLocation > 0 && futureLocation < 100_001 && move <= shortestMove[futureLocation])
    {
        q.Enqueue(futureLocation, move);
        shortestMove[futureLocation] = move;
    }
}

Console.WriteLine(shortestMove[conditions[1]]);
