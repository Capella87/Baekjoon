// 백준 24511번 문제 : queuestack
// https://www.acmicpc.net/problem/24511
// 알고리즘 분류 : 자료 구조, 스택, 덱, 큐

using System.Text;

// Faster than Console class
StreamReader fasterReader = new (new BufferedStream(Console.OpenStandardInput()));
StreamWriter fasterWriter = new (new BufferedStream(Console.OpenStandardOutput()));

int n = int.Parse(fasterReader.ReadLine());

var a = Array.ConvertAll<string, int>(fasterReader.ReadLine().Split(' '), int.Parse);
var b = Array.ConvertAll<string, int>(fasterReader.ReadLine().Split(' '), int.Parse);
var queueStack = new List<int>();

int i = n - 1;
for (; i >= 0; i--)
{
    if (a[i] == 0) // Queue
    {
        queueStack.Add(b[i]);
    }
}

int m = int.Parse(fasterReader.ReadLine());
var c = Array.ConvertAll<string, int>(fasterReader.ReadLine().Split(' '), int.Parse);

i = 0;
var sb = new StringBuilder();

while (m > 0 && i < queueStack.Count)
{
    sb.Append(queueStack[i]).Append(' ');
    m--;
    i++;
}
for (i = 0; i < m; i++)
{
    sb.Append(c[i]).Append(' ');
}
// StreamWriter can process StringBuilder directly.
fasterWriter.WriteLine(sb);

// Close to flush and write to the console.
fasterWriter.Close();
