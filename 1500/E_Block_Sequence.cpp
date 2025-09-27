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

int helper(int index, int n, vector<int> &nums, vector<int> &dp)
{
    if (index == n)
        return 0;
    if (index > n)
        return INT_MAX;

    if (dp[index] != -1)
        return dp[index];

    int take = helper(index + nums[index] + 1, n, nums, dp);
    int del = helper(index + 1, n, nums, dp);
    int noTake = del == INT_MAX ? INT_MAX : del + 1;

    return dp[index] = min(take, noTake);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> dp(n + 1, -1);

    cout << helper(0, n, nums, dp);
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