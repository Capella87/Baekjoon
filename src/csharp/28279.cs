// 백준 28279번 문제 : 덱 2
// https://www.acmicpc.net/problem/28279
// 알고리즘 분류 : 자료 구조, 덱

// Very naive solution

using System.Collections.Generic;
using System.Buffers;
using System.Text;

int n = int.Parse(Console.ReadLine());

var deque = new LinkedList<int>();
int[] arguments;
var buff = new StringBuilder();
LinkedListNode<int>? node = null;

for (int i = 0; i < n; i++)
{
    arguments = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
    
    switch (arguments[0])
    {
        case 1:
            deque.AddFirst(arguments[1]);
            break;
        case 2:
            deque.AddLast(arguments[1]);
            break;
        case 3:
            node = deque.First;
            if (node != null)
            {
                buff.AppendLine(node.Value.ToString());
                deque.RemoveFirst();
            }
            else
                buff.AppendLine("-1");
            break;
        case 4:
            node = deque.Last;
            if (node != null)
            {
                buff.AppendLine(node.Value.ToString());
                deque.RemoveLast();
            }
            else
                buff.AppendLine("-1");
            break;
        case 5:
            buff.AppendLine(deque.Count.ToString());
            break;
        case 6:
            buff.AppendLine(deque.Count > 0 ? "0" : "1");
            break;
        case 7:
            node = deque.First;
            if (node != null)
                buff.AppendLine(node.Value.ToString());
            else
                buff.AppendLine("-1");
            break;
        case 8:
            node = deque.Last;
            if (node != null)
                buff.AppendLine(node.Value.ToString());
            else
                buff.AppendLine("-1");
            break;
    }
}

Console.Write(buff.ToString());
