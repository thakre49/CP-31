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

/*

x + xy = n
x(1+y) = n;



*/

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2;
        br;
        return;
    }

    int ans = 1;

    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (n % i == 0)
        {
            ans = max(ans, i);
            ans = max(ans, n / i);
        }
    }
    cout << ans << " " << n - ans;
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