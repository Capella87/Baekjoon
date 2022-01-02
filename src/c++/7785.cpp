// 백준 7785번 문제 : 회사에 있는 사람
// https://www.acmicpc.net/problem/7785
// 알고리즘 분류 : 자료 구조, 해시를 사용한 집합과 맵

#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string input;
    map<string, bool> people;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        int space_location = int(input.find(' '));
        if (input.substr(space_location + 1) == "enter")
            people.insert({ input.substr(0, space_location), "true" });
        else people.erase(input.substr(0, space_location));
    }
    for (map<string, bool>::reverse_iterator it = people.rbegin(); it != people.rend(); it++)
        cout << it->first << '\n';

    return 0;
}