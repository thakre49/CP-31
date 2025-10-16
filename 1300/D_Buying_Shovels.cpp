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

    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int fac1 = i;
            int fac2 = n / i;

            int pos1 = fac1 <= k ? n / fac1 : n;
            int pos2 = fac2 <= k ? n / fac2 : n;

            ans = min(ans, min(pos1, pos2));
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