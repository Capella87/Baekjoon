// 백준 5076번 문제 : Web Page
// https://www.acmicpc.net/problem/5076
// 알고리즘 분류 : 자료 구조, 문자열, 파싱, 스택

using System.Text;

var tagChars = new[] { '>', ' ' };
int tagLen = 0, l;
var sb = new StringBuilder();

while (true)
{
    var input = Console.ReadLine();
    if (input == "#") break;
    var stk = new Stack<string>();
    bool isIllegal = false;
    for (int i = 0; i < input.Length; i++)
    {
        while (input[i] != '<' && i < input.Length - 1) i++;
        if (input[i] == '<')
        {
            if (input[i + 1] == '/')
            {
                i += 2;
                l = input.IndexOf('>', i);
                tagLen = l - i;
                if (stk.Count == 0 || stk.Peek() != input.Substring(i, tagLen))
                {
                    isIllegal = true;
                    break;
                }
                stk.Pop();
            }
            else
            {
                l = input.IndexOfAny(tagChars, i);
                tagLen = l - ++i;
                string tag = input.Substring(i, tagLen);
                if (input[l] == '>') stk.Push(tag);
                else
                {
                    l = input.IndexOf('>', l + 1);
                    if (input[l - 1] == '/') i = l;
                    else stk.Push(tag);
                }
            }
        }
    }
    sb.AppendLine(isIllegal || stk.Count != 0 ? "illegal" : "legal");
}
Console.Write(sb.ToString());
