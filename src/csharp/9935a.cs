// 백준 9935번 문제 : 문자열 폭발
// https://www.acmicpc.net/problem/9935
// 알고리즘 분류 : 자료 구조, 문자열, 스택

// Naive solution

using System.Text;

var strInput = Console.ReadLine();
char[] finStrInput = strInput.ToCharArray();
char[] bombKeyword = Console.ReadLine().ToCharArray();
int bombIdx = 0, tempIdx;
var buff = new StringBuilder();
var bombStack = new Stack<(int bombIdx, int idx)>();

for (int i = 0; i < strInput.Length; i++)
{
    // Init or reset
    if (strInput[i] == bombKeyword[0])
    {
        bombStack.Push((0, i));
        bombIdx = 1;
    }
    else if (strInput[i] == bombKeyword[bombIdx])
    {
        bombStack.Push((bombIdx++, i));
    }
    else
    {
        bombStack.Clear();
        bombIdx = 0;
        continue;
    }

    if (bombIdx == bombKeyword.Length)
    {
        for (int j = 0; j < bombKeyword.Length; j++)
        {
            tempIdx = bombStack.Pop().idx;
            finStrInput[tempIdx] = '\0';
        }

        bombIdx = bombStack.Count > 0 ? bombStack.Peek().bombIdx + 1 : 0;
    }
}

for (int i = 0; i < strInput.Length; i++)
{
    if (finStrInput[i] == '\0') continue;
    buff.Append(finStrInput[i]);
}

if (buff.Length > 0)
    Console.WriteLine(buff.ToString());
else
    Console.WriteLine("FRULA");
