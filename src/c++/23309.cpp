// 백준 23309번 문제 : 철도 공사
// https://www.acmicpc.net/problem/23309
// 알고리즘 분류 : 구현, 자료 구조, 연결 리스트

#include <iostream>
#include <string>
using namespace std;

typedef struct station
{
    int next;
    int prev;
} station;

station* line[1000001] = { NULL, };
int lead_idx = 0;

void init_station(int* arr, const int init_count)
{
    for (int i = 0; i < init_count; i++)
    {
        line[arr[i]] = new station;
        if (!i) // first
        {
            line[arr[i]]->next = arr[(i + 1) % init_count];
            line[arr[i]]->prev = arr[init_count - 1];
            lead_idx = arr[i];
        }
        else if (i == init_count - 1) // last
        {
            line[arr[i]]->next = arr[0];
            line[arr[i]]->prev = arr[i - 1];
        }
        else // leftovers
        {
            line[arr[i]]->next = arr[i + 1];
            line[arr[i]]->prev = arr[i - 1];
        }
    }
}

void construct(string& command, const int i, const int j)
{
    line[j] = new station;
    if (command == "BN")
    {
        int nxt = line[i]->next;
        cout << nxt << '\n';
        line[nxt]->prev = j;
        line[i]->next = j;
        line[j]->prev = i;
        line[j]->next = nxt;
    }
    else
    {
        int prv = line[i]->prev;
        cout << prv << '\n';
        line[prv]->next = j;
        line[i]->prev = j;
        line[j]->prev = prv;
        line[j]->next = i;
    }
}

void demolish(string& command, const int i)
{
    if (command == "CN") // Remove next;
    {
        int nxt = line[i]->next;
        cout << nxt << '\n';
        if (lead_idx == nxt)
            lead_idx = i;
        line[line[nxt]->next]->prev = i;
        line[i]->next = line[nxt]->next;
        delete[] line[nxt];
        line[nxt] = NULL;
    }
    else // Remove previous;
    {
        int prv = line[i]->prev;
        cout << prv << '\n';
        if (lead_idx == prv)
            lead_idx = i;
        line[line[prv]->prev]->next = i;
        line[i]->prev = line[prv]->prev;
        delete[] line[prv];
        line[prv] = NULL;

    }
}

// Remove all stations using lead_idx;
void remove_all(void)
{
    int idx = line[lead_idx]->next;
    int prev = lead_idx;
    while (idx != lead_idx)
    {
        prev = idx;
        idx = line[idx]->next;
        delete[] line[prev];
        line[prev] = NULL;
    }
    delete[] line[lead_idx]; // Remove the lead_idx 'station' node in last.
    line[lead_idx] = NULL;
    lead_idx = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int j, target;
    string command;
     
    cin >> n >> m;
    
    // Initial stations
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    init_station(arr, n);

    // Work regarding stations
    cin.get();
    for (int i = 0; i < m; i++)
    {
        cin >> command >> j;

        if (command == "BN" || command == "BP")
        {
            cin >> target;
            construct(command, j, target);
        }
        else demolish(command, j);
        cin.get();
    }

    remove_all();
    delete[] arr;
    return 0;
}