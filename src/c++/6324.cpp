// 백준 6324번 문제 : URLs
// https://www.acmicpc.net/problem/6324
// 알고리즘 분류 : 문자열, 많은 조건 분기, 파싱

#include <iostream>
#include <string>
using namespace std;

void process(string& target, const int idx)
{
    string proc, host, port, path;

    // Protocol
    size_t sep = target.find("://");
    proc = target.substr(0, sep);
    sep += 3;

    // Port and path
    size_t port_idx = target.find(':', sep);
    size_t path_idx = target.find('/', sep);
    size_t common_idx = sep;

    if (port_idx != string::npos && path_idx != string::npos)
    {
        if (port_idx > path_idx)
        {
            port = "<default>";
            path = target.substr(path_idx + 1);
            common_idx = path_idx;
        }
        else
        {
            port = target.substr(port_idx + 1, path_idx - port_idx - 1);
            path = target.substr(path_idx + 1);
            common_idx = port_idx;
        }
    }
    else if (port_idx == string::npos && path_idx != string::npos)
    {
        port = "<default>";
        path = target.substr(path_idx + 1);
        common_idx = path_idx;
    }
    else if (port_idx != string::npos && path_idx == string::npos)
    {
        port = target.substr(port_idx + 1);
        path = "<default>";
        common_idx = port_idx;
    }
    else if (port_idx == string::npos && path_idx == string::npos)
    {
        port = path = "<default>";
        common_idx = target.length();
    }

    // A unified separator for host
    host = target.substr(sep, common_idx - sep);

    // Print results
    cout << "URL #" << idx << '\n';
    cout << "Protocol = " << proc << '\n';
    cout << "Host     = " << host << '\n';
    cout << "Port     = " << port << '\n';
    cout << "Path     = " << path << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin, input);
        process(input, i + 1);
        cout << '\n';
    }

    return 0;
}