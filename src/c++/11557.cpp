// 백준 11557번 문제 : Yangjojang of The Year
// https://www.acmicpc.net/problem/11557
// 알고리즘 분류 : 정렬

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
    int t, n;
    string school, maxSchool;
    int count, maxCount;

    cin >> t;
    for (int i = 0; i < t; i++) // test case
    {
        cin >> n;

        cin >> school >> count;
        maxSchool = school;
        maxCount = count;
        for (int j = 0; j < n - 1; j++) // schools
        {
            cin >> school >> count;
            if (maxCount < count)
            {
                maxSchool = school;
                maxCount = count;
            }
        }
        cout << maxSchool << '\n';
    }
    return 0;
}