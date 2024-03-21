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

    // Init or reset; Note: If there is ongoing bomb keyword and strInput[i] is the first character of the keyword,
    // bombIdx is reset to 0, but the stack is NOT cleared.
    if (strInput[i] == bombKeyword[0])
    {
        bombStack.Push(0);
        bombIdx = 1;
    }
    // Ongoing bomb keyword and order is correct.
    else if (strInput[i] == bombKeyword[bombIdx])
        bombStack.Push(bombIdx++);
    // Clear the stack if strInput[i] is NOT keyword characters at all
    // or wrong order (e.g. keyword is "asdf", but previous characters are "as" and strInput[i] is "f")
    else
    {
        bombStack.Clear();
        bombIdx = 0;
        continue;
    }

    // Activate the bomb if the bomb word is fully matched
    // Note: This checks the bomb keyword (trigger) every time regardless of the characters match
    if (bombIdx == bombKeyword.Length)
    {
        // Pop the keyword
        for (int j = 0; j < bombKeyword.Length; j++)
            bombStack.Pop();

        buff.Remove(buff.Length - bombIdx, bombIdx);

        // Check the previous ongoing 'bomb' and ready to continue matching
        bombIdx = bombStack.Count > 0 ? bombStack.Peek() + 1 : 0;
    }
}

if (buff.Length > 0) Console.WriteLine(buff.ToString());
else Console.WriteLine("FRULA");
