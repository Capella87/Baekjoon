// 백준 10825번 문제 : 국영수
// https://www.acmicpc.net/problem/10825
// 알고리즘 분류 : 정렬

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct classmates
{
    string name;
    int korean;
    int english;
    int math;
}Mates;

// compare function compatible to string::sort
// returns true (not sorting; false to sort)
bool compare(const Mates& a, const Mates& b)
{
    if (a.korean > b.korean) return true;
    else if (a.korean < b.korean) return false;
    else
    {
        if (a.english > b.english) return false;
        else if (a.english < b.english) return true;
        else
        {
            if (a.math > b.math) return true;
            else if (a.math < b.math) return false;
            else
            {
                int rt = a.name.compare(b.name);
                return rt < 0 ? true : false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    cin.get();
    Mates* people = new Mates[n];
    for (int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].korean >> people[i].english >> people[i].math;
        cin.get();
    }
    sort(people, people + n, compare);
    for (int i = 0; i < n; i++)
        cout << people[i].name << '\n';
    delete[] people;
    return 0;
}