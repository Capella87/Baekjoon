// 백준 17478번 문제 : 재귀함수가 뭔가요?
// https://www.acmicpc.net/problem/17478
// 알고리즘 분류 : 재귀

using System;

namespace recursive
{
    class Recursive
    {
        public string underbar = "";

        public void WhatIsRecursive(int n)
        {
            string line = underbar;
            Console.WriteLine(line + "\"재귀함수가 뭔가요?\"");
            if (n == 0)
                Console.WriteLine(line + "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
            else
            {
                Console.WriteLine(line + "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
                Console.WriteLine(line + "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
                Console.WriteLine(line + "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
                underbar += "____";
                WhatIsRecursive(n - 1);
            }
            Console.WriteLine(line + "라고 답변하였지.");
        }

        static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Recursive r = new Recursive();
            Console.WriteLine("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
            r.WhatIsRecursive(n);
        }
    }
}