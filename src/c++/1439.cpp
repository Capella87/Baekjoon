// 백준 1439번 문제 : 뒤집기
// https://www.acmicpc.net/problem/1439
// 알고리즘 분류 : 그리디 알고리즘, 문자열

#include <iostream>
#include <string>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

string s;
int chunkCount[2] = { 0, 0 };
int chunkLen = 0;

int getMinimumActionCount()
{
    int current = s[0] - '0';
    chunkCount[current] = 1;
    size_t len = s.length();
    for (size_t i = 1; i < len; i++)
    {
        if ((s[i] - '0') == current) continue;
        current = s[i] - '0';
        chunkCount[current]++;
    }

    return MIN(chunkCount[0], chunkCount[1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    cout << getMinimumActionCount() << '\n';
    return 0;
}
