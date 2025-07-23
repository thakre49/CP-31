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
int calPow(int n, int k, int MOD)
{
    long long ans = 1;
    while (k--)
    {
        ans = (ans * n) % MOD;
    }

    return (int)ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << calPow(n, k, 1000000007);
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