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

ll helper(int index, int last, int n, vector<ll> &a, vector<ll> &b, vector<vector<ll>> &dp)
{
    if (index == n)
        return 0;

    if (dp[index][last] != -1)
        return dp[index][last];

    ll notTake = helper(index + 1, last, n, a, b, dp);
    ll take = 0;

    if (last == 2)
    {
        take = helper(index + 1, 1, n, a, b, dp) + a[index];
    }
    else if (last == 1)
    {
        take = helper(index + 1, 2, n, a, b, dp) + b[index];
    }
    else
    {
        take = max(helper(index + 1, 1, n, a, b, dp) + a[index],
                   helper(index + 1, 2, n, a, b, dp) + b[index]);
    }

    return dp[index][last] = max(take, notTake);
}

void solve()
{
    /*
    dp[i][x] = max height we can get from i to n if last taken from x
    x = [0,1,2] [not taken, 1st, 2nd]
    */
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];

    vector<vector<ll>> dp(n, vector<ll>(3, -1));

    cout << helper(0, 0, n, a, b, dp);
    br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
