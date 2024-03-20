// 백준 11382번 문제 : 꼬마 정민
// https://www.acmicpc.net/problem/11382
// 알고리즘 분류 : 수학, 구현, 사칙연산

using System.Numerics;

var inputs = Array.ConvertAll<string, BigInteger>(Console.ReadLine().Split(' '), BigInteger.Parse);

var result = BigInteger.Add(inputs[0], inputs[1]);
result = BigInteger.Add(result, inputs[2]);
Console.WriteLine(result.ToString());
