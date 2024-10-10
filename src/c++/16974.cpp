// 백준 16974번 문제 : 레벨 햄버거
// https://www.acmicpc.net/problem/16974
// 알고리즘 분류 : 다이나믹 프로그래밍, 분할 정복, 재귀

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, cached_level = 0;
ll x;
vector<ll> cache;

ll calc_level_hamburger(int n)
{
    ll rt = 1;
    cache.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        rt = rt * 2 + 3;
        cache.push_back(cache[cached_level++] * 2 + 1);
    }
    return rt;
}

ll count_eaten_patties(ll left, ll right, ll eaten_layers_idx, int level)
{
    if ((eaten_layers_idx <= left) && (level > 0)) return 0;
    if (level == 0) return 1;

    ll count = 0;
    ll mid = (left + right) / 2;
    if (eaten_layers_idx < (left + level)) return 0;
    else if (((left + level) <= eaten_layers_idx) && (eaten_layers_idx < (mid - level)))
    {
        return count += count_eaten_patties(left + 1, mid - 1, eaten_layers_idx, level - 1);
    }
    else count += cache[level - 1];

    if (eaten_layers_idx >= mid) count++;
    if (eaten_layers_idx >= (mid + level) && eaten_layers_idx < (right - level))
        return count += count_eaten_patties(mid + 1, right - 1, eaten_layers_idx, level - 1);
    else if (eaten_layers_idx >= (right - level)) count += cache[level - 1];
    return count;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    ll total = calc_level_hamburger(n);
    cache.push_back(1);
    cached_level = 1;
    ll patties = count_eaten_patties(0, total - 1, x - 1, n);
    cout << patties << '\n';

    return 0;
}
