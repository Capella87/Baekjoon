// 백준 2346번 문제 : 풍선 터뜨리기
// https://www.acmicpc.net/problem/2346
// 알고리즘 분류 : 자료 구조, 덱

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    deque<pair<int, int>> balloons;
    int n, temp, i;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        balloons.push_back({ i + 1, temp});
    }
    pair<int, int> f = balloons.front();
    balloons.pop_front();
    int moveCount = f.second >= 0 ? f.second : f.second * (-1);
    moveCount = balloons.empty() ? moveCount : moveCount % balloons.size();
    bool isNegative = f.second >= 0 ? false : true;
    cout << "1 ";
    int current = 1;
    while (current < n)
    {
        i = 0;
        while (!isNegative && i < moveCount)
        {
            balloons.push_back(balloons.front());
            balloons.pop_front();
            i++;
        }
        while (isNegative && i < moveCount)
        {
            balloons.push_front(balloons.back());
            balloons.pop_back();
            i++;
        }
        if (!isNegative)
        {
            f = balloons.back();
            balloons.pop_back();
        }
        else
        {
            f = balloons.front();
            balloons.pop_front();
        }
        cout << f.first << ' ';
        moveCount = f.second >= 0 ? f.second : f.second * (-1);
        moveCount = balloons.empty() ? moveCount : moveCount % balloons.size();
        isNegative = f.second >= 0 ? false : true;
        current++;
    }
    cout << '\n';
    return 0;
}