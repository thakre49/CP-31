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
    int n, x, m;
    cin >> n >> x >> m;

    int l = x;
    int r = x;
    for (int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        if (!((d < l) || (c > r)))
        {
            l = min(l, c);
            r = max(r, d);
        }
    }
    cout << r - l + 1;
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