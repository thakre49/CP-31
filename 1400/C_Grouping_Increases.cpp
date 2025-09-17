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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int g1 = INT_MAX;
    int g2 = INT_MAX;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= g1 && nums[i] <= g2)
        {
            if (g1 < g2)
            {
                g1 = nums[i];
            }
            else
                g2 = nums[i];
        }
        else if (nums[i] > g1 && nums[i] > g2)
        {
            if (g1 < g2)
            {
                g1 = nums[i];
            }
            else
                g2 = nums[i];
            ans++;
        }
        else
        {
            if (g1 >= nums[i])
            {
                g1 = nums[i];
            }
            else
                g2 = nums[i];
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