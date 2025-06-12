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
    vector<vector<long long>> nums(m, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[j][i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        sort(nums[i].begin(), nums[i].end());
        long long currentSum = 0;
        for (int j = 0; j < n; j++)
        {
            ans += ((nums[i][j] * j) - currentSum);
            currentSum += nums[i][j];
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