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
typedef pair<ll, ll> pri;
typedef unordered_map<ll, ll> umi;
typedef map<ll, ll> mi;

// Macros
#define pb push_back
#define br cout << "\n"
long long x = 1000000000000000000LL;
//****************************************************************
void solve()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ll posNum = n - 1;
    if (nums[n - 2] > nums[n - 1])
    {
        cout << -1;
        br;
        return;
    }

    ll count = 0;
    vector<pair<ll, pair<ll, ll>>> ans;

    for (ll i = n - 3; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {

            if (nums[posNum] >= 0)
            {
                nums[i] = nums[i + 1] - nums[posNum];
                if (abs(nums[i]) >= x)
                {
                    cout << -1;
                    br;
                    return;
                }
                count++;
                ans.push_back({i, {i + 1, posNum}});
            }
            else
            {
                cout << -1;
                br;
                return;
            }
        }
        if (nums[i + 1] >= 0 && nums[posNum] > nums[i + 1])
        {
            posNum = i + 1;
        }
    }

    cout << count;
    br;
    for (auto it : ans)
    {
        cout << it.first + 1 << " " << it.second.first + 1 << " " << it.second.second + 1;
        br;
    }
}

int main()
{
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
