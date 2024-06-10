// 백준 1715번 문제 : 카드 정렬하기
// https://www.acmicpc.net/problem/1715
// 알고리즘 분류 : 자료 구조, 그리디 알고리즘, 우선순위 큐

int n = int.Parse(Console.ReadLine());
int compCount = 0, sum;
var pq = new PriorityQueue<int, int>();

for (int i = 0; i < n; i++)
{
    var cards = int.Parse(Console.ReadLine());
    pq.Enqueue(cards, cards);
}

while (pq.Count > 1)
{
    sum = pq.Dequeue() + pq.Dequeue();

    compCount += sum;
    pq.Enqueue(sum, sum);
}
Console.WriteLine(compCount);
