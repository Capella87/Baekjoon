// 백준 2745번 문제 : 진법 변환
// https://www.acmicpc.net/problem/2745
// 알고리즘 분류 : 수학, 구현, 문자열

var input = Console.ReadLine().Split(' ');
var raw = input[0];
uint nary = uint.Parse(input[1]);
uint b = 1, result = 0;

for (int i = raw.Length - 1; i >= 0; i--)
{
    result += GetInt(raw[i]) * b;
    b *= nary;
}

Console.WriteLine(result);

uint GetInt(char input)
{
    return (input >= '0' && input <= '9')
        ? (uint)(input - '0') : (uint)(input - 'A' + 10);
}
