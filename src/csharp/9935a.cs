// 백준 9935번 문제 : 문자열 폭발
// https://www.acmicpc.net/problem/9935
// 알고리즘 분류 : 자료 구조, 문자열, 스택

// Naive solution

using System.Text;

string strInput = Console.ReadLine();
string bombKeyword = Console.ReadLine();
int bombIdx = 0;
var buff = new StringBuilder();
var bombStack = new Stack<int>();

for (int i = 0; i < strInput.Length; i++)
{
    buff.Append(strInput[i]);

    // Init or reset
    if (strInput[i] == bombKeyword[0])
    {
        bombStack.Push(0);
        bombIdx = 1;
    }
    else if (strInput[i] == bombKeyword[bombIdx])
        bombStack.Push(bombIdx++);
    else
    {
        bombStack.Clear();
        bombIdx = 0;
        continue;
    }

    if (bombIdx == bombKeyword.Length)
    {
        for (int j = 0; j < bombKeyword.Length; j++)
            bombStack.Pop();

        buff.Remove(buff.Length - bombIdx, bombIdx);
        bombIdx = bombStack.Count > 0 ? bombStack.Peek() + 1 : 0;
    }
}

if (buff.Length > 0) Console.WriteLine(buff.ToString());
else Console.WriteLine("FRULA");
