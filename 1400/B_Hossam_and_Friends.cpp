/*
1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<int, int> pri;
typedef unordered_map<int, int> umi;
typedef map<int, int> mi;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> notFriends(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        notFriends[i] = {min(a, b), max(a, b)};
    }
    sort(notFriends.begin(), notFriends.end());

    vector<int> minEnd(m + 1, n + 4);
    for (int i = m - 1; i >= 0; i--)
    {
        minEnd[i] = min(notFriends[i].second, minEnd[i + 1]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int nexInd = lower_bound(notFriends.begin(), notFriends.end(), make_pair(i, 0)) - notFriends.begin();
        if (nexInd < notFriends.size())
        {

            ans += (minEnd[nexInd] - i);
        }
        else
            ans += (n - i + 1);
    }

    cout << ans;
    br;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}