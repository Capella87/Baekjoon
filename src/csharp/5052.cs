// 백준 5052번 문제 : 전화번호 목록
// https://www.acmicpc.net/problem/5052
// 알고리즘 분류 : 자료 구조, 문자열, 정렬, 트리, 트라이

using System;
using System.Collections.Generic;
using System.Text;

namespace Phonebook
{
    public class Trie
    {
        internal class Node
        {
            internal bool _isEndOfString;
            internal Dictionary<char, Node> _children;

            internal Node()
            {
                _isEndOfString = false;
                _children = new Dictionary<char, Node>();
            }
        }

        private Node _root;

        public Trie()
        {
            _root = new Node();
        }
        
        public bool Add(string str)
        {
            Node cur = _root;
            bool isConsistent = true;

            int idx = 0;
            while (idx < str.Length)
            {
                if (!cur._children.ContainsKey(str[idx]))
                    cur._children.Add(str[idx], new Node());
                cur = cur._children[str[idx++]];
            }
            cur._isEndOfString = true;
            return isConsistent;
        }
    }

    public static class MainApp
    {
        public static void Main()
        {

            int t = int.Parse(Console.ReadLine());
            var result = new StringBuilder();
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                int input;
                bool rt = true;
                var tri = new Trie();
                for (int i = 0; i < n; i++)
                {
                    input = int.Parse(Console.ReadLine());
                    rt &= tri.Add(input);
                }
                if (!rt) result.AppendLine("NO");
                else result.AppendLine("YES");
            }
            Console.Write(result.ToString());
        }
    }
}