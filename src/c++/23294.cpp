// 백준 23300번 문제 : 웹 브라우저 1
// https://www.acmicpc.net/problem/23294
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 덱

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, c, current = 0, target; // c for max cache size
    int usage = 0;
    char op;
    deque<int> backward, frontward;

    cin >> n >> q >> c;
    int* cache_size = new int[n];
    for (int i = 0; i < n; i++)
        cin >> cache_size[i];
    cin.get();
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        switch (op)
        {
        case 'B':
            if (backward.size())
            {
                frontward.push_front(current);
                current = backward.front();
                backward.pop_front();
            }
            break;

        case 'F':
            if (frontward.size())
            {
                backward.push_front(current);
                current = frontward.front();
                frontward.pop_front();
            }
            break;

        case 'A':
            cin >> target;
            cin.get();

            while (!frontward.empty())
            {
                usage -= cache_size[frontward.front() - 1];
                frontward.pop_front();
            }
            if (current)
                backward.push_front(current);
            current = target;
            usage += cache_size[target - 1];

            // Remove the oldest cached sites if the usage is exceed the limit
            while (usage > c && !backward.empty())
            {
                usage -= cache_size[backward.back() - 1];
                backward.pop_back();
            }
            break;

        case 'C':
            deque<int> temp;
            while (!backward.empty())
            {
                if (temp.empty() || temp.front() != backward.back())
                    temp.push_front(backward.back());
                else usage -= cache_size[backward.back() - 1];
                backward.pop_back();
            }
            backward = temp;
            break;
        }
    }

    cout << current << '\n';
    if (backward.empty()) cout << "-1\n";
    else
    {
        while (!backward.empty())
        {
            cout << backward.front() << ' ';
            backward.pop_front();
        }
        cout << '\n';
    }
    if (frontward.empty()) cout << "-1\n";
    else
    {
        while (!frontward.empty())
        {
            cout << frontward.front() << ' ';
            frontward.pop_front();
        }
        cout << '\n';
    }

    delete[] cache_size;
    return 0;
}