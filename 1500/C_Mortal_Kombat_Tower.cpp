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

int helper(int index, int n, int turn, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index][turn] != -1)
        return dp[index][turn];

    int one = helper(index + 1, n, 1 - turn, nums, dp);
    int two = helper(index + 2, n, 1 - turn, nums, dp);

    one = turn == 0 ? one + nums[index] : one;
    two = turn == 0 ? two + nums[index] + nums[index + 1] : two;

    return dp[index][turn] = min(one, two);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> dp(n + 2, vector<int>(2, -1));

    cout << helper(0, n, 0, nums, dp);
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
