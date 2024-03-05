// 백준 14425번 문제 : 문자열 집합
// https://www.acmicpc.net/problem/14425
// 알고리즘 분류 : 자료 구조, 문자열, 트리, 트리를 사용한 집합과 맵, 트라이

// Map data structure based code;

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, count = 0;
    string input;
    map<string, int> s;

    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        s.insert({ input, 0 });
    }
    for (int i = 0; i < m; i++)
    {
        getline(cin, input);
        if (s.find(input) != s.end())
            count++;
    }
    cout << count << '\n';

    return 0;
}