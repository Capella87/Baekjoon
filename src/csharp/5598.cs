// 백준 5598번 문제 : 카이사르 암호
// https://www.acmicpc.net/problem/5598
// 알고리즘 분류 : 구현, 문자열

using System;

namespace ceasar
{
    class Ceasar
    {
        static void Main()
        {
            string encryptedStr = Console.ReadLine();
            string decryptedStr = "";
            for (int i = 0; i < encryptedStr.Length; i++)
                decryptedStr += Convert.ToChar(('Z' - 'A' + encryptedStr[i] - 'A' - 2) % 26 + 'A');
            Console.WriteLine(decryptedStr);
        }
    }
}