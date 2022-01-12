// 백준 19583번 문제 : 싸이버개강총회
// https://www.acmicpc.net/problem/19583
// 알고리즘 분류 : 구현, 자료 구조, 문자열, 파싱, 해시를 사용한 집합과 맵

#include <iostream>
#include <map>
#include <string>
using namespace std;

int parse_time(string& s)
{
    return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, e, q;
    string input;
    int begin, end, end_streaming, attendee = 0;
    map<string, int> people;

    cin >> s >> e >> q;
    cin.get();
    begin = parse_time(s);
    end = parse_time(e);
    end_streaming = parse_time(q);
    while (getline(cin, input))
    {
        int t = parse_time(input);
        string name = input.substr(6, input.length() - 5);
        if (t <= begin)
        {
            map<string, int>::iterator it = people.find(name);
            if (it == people.end())
                people.insert({ name, 0 });
        }
        else if (t >= end && t <= end_streaming)
        {
            map<string, int>::iterator it = people.find(name);
            if (it != people.end())
            {
                attendee++;
                people.erase(it);
            }
        }
    }
    cout << attendee << '\n';

    return 0;
}