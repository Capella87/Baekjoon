// 백준 5430번 문제 : AC
// https://www.acmicpc.net/problem/5430
// 알고리즘 분류 : 구현, 자료 구조, 문자열, 파싱, 덱

#include <iostream>
#include <deque>
#include <string>
using namespace std;

void getNum(deque<int>& dq, string& arr)
{
    size_t pos = 1;
    size_t cur = pos;
    if (arr.length() == 2) return;
    while (1)
    {
        if ((pos = arr.find(",", cur)) == string::npos)
        {
            pos = arr.find("]", cur);
            dq.push_back(stoi(arr.substr(cur, pos - cur)));
            break;
        }
        dq.push_back(stoi(arr.substr(cur, pos - cur)));
        cur = pos + 1;
    }
}

void printDeque(deque<int>& dq, const bool isReversed)
{
    cout << '[';
    if (isReversed)
    {
        while (!dq.empty())
        {
            cout << dq.back();
            dq.pop_back();
            if (!dq.empty()) cout << ',';
        }
    }
    else
    {
        while (!dq.empty())
        {
            cout << dq.front();
            dq.pop_front();
            if (!dq.empty()) cout << ',';
        }
    }
    cout << "]\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, arr_count;
    string funct, arr;
    
    cin >> t;
    cin.get();
    for (int i = 0; i < t; i++)
    {
        getline(cin, funct);
        size_t len = funct.length();
        cin >> arr_count;
        cin.get();
        getline(cin, arr);
        deque<int> dq;
        getNum(dq, arr);

        bool isError = false, isReversed = false;
        for (int j = 0; j < len; j++)
        {
            switch (funct[j])
            {
            case 'R':
                isReversed = !isReversed;
                break;
            case 'D':
                if (dq.empty())
                {
                    isError = true;
                    break;
                }
                else if (isReversed) dq.pop_back();
                else if (!isReversed) dq.pop_front();
                break;
            }
            if (isError)
            {
                cout << "error\n";
                break;
            }
        }
        if (!isError) printDeque(dq, isReversed);
    }
    return 0;
}