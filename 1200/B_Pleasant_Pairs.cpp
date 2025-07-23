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
    vector<pair<ll, ll>> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i].first * nums[j].first >= 2 * n)
            {
                break;
            }
            else if (nums[i].first * nums[j].first == nums[i].second + nums[j].second)
            {
                ans++;
            }
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