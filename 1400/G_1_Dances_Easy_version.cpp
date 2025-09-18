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
    vector<int> a(n);
    vector<int> b(n);
    a[0] = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    auto start = b.begin();
    auto end = b.end();
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(start, end, a[i]);
        if (it == b.end())
        {
            ans = n - i;
            break;
        }
        else
        {
            start = ++it;
        }
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