// 백준 1431번 문제 : 시리얼 번호
// https://www.acmicpc.net/problem/1431
// 알고리즘 분류 : 정렬

using System;
using System.Collections;

namespace SerialNumber
{
    public class SerialComparer : IComparer // Comparer
    {
        public int Compare(Object t1, Object t2)
        {
            string a = Convert.ToString(t1);
            string b = Convert.ToString(t2);

            if (a.Length < b.Length) return -1;
            else if (a.Length > b.Length) return 1;
            else
            {
                int aTot = GetTotal(a);
                int bTot = GetTotal(b);

                if (aTot < bTot) return -1;
                else if (aTot > bTot) return 1;
                else if (string.Compare(a, b) < 0) return -1;
                else return 1;
            }

            int GetTotal(string a)
            {
                int total = 0;
                foreach (char c in a)
                    if (c >= '0' && c <= '9')
                        total += (char)(c - '0');
                return total;
            }
        }
    }

    public class SerialNumber
    {
        private int _size;
        private string[] _serialArr;

        public SerialNumber(int n)
        {
            _size = n;
            _serialArr = new string[_size];

            for (int i = 0; i < _size; i++)
                _serialArr[i] = Console.ReadLine();
        }

        public void SortArray()
        {
            IComparer criteria = new SerialComparer();
            Array.Sort(_serialArr, criteria);
        }

        public void PrintArray()
        {
            foreach (string s in _serialArr)
                Console.WriteLine(s);
        }
    }

    public static class MainApp
    {
        public static void Main()
        {
            SerialNumber a = new(Convert.ToInt32(Console.ReadLine()));
            a.SortArray();
            a.PrintArray();
        }
    }
}