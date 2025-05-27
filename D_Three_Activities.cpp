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

int helper(int day, int state, int n, vector<vector<int>> &activities, vector<vector<int>> &dp)
{
    if (day == n || state == 7)
        return 0;

    if (dp[day][state] != INT_MIN)
        return dp[day][state];
    int ans = 0;
    ans = max(ans, helper(day + 1, state, n, activities, dp));
    for (int i = 0; i < 3; i++)
    {
        if ((state & (1 << i)) == 0)
        {
            int newState = (state | (1 << i));
            ans = max(ans, activities[i][day] + helper(day + 1, newState, n, activities, dp));
        }
    }

    return dp[day][state] = ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> activities(3, vector<int>(n));

    for (int i = 0; i < n; i++)
        cin >> activities[0][i];
    for (int i = 0; i < n; i++)
        cin >> activities[1][i];
    for (int i = 0; i < n; i++)
        cin >> activities[2][i];

    vector<vector<int>> dp(n, vector<int>(8, INT_MIN));

    cout
        << helper(0, 0, n, activities, dp);
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