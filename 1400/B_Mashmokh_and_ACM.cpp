/*
1 2 3
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
long long helper(int prev, int total, int n, vector<vector<int>> &dp)
{
    if (total == 0)
        return 1;
    if (dp[prev][total] != -1)
        return dp[prev][total];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((prev * i) > n)
            break;
        else
        {
            ans = (ans + helper(prev * i, total - 1, n, dp)) % mod;
        }
    }

    return dp[prev][total] = ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout
        << helper(1, k, n, dp);
    br;
}

int main()
{

    solve();

    return 0;
}