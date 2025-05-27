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
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    long long ans = 1;

    for (int i = 1; i <= 60; i++)
    {
        ans = (1LL << i);
        set<long long> s;
        for (int j = 0; j < n; j++)
        {
            s.insert(nums[j] % ans);
        }
        if (s.size() == 2)
        {
            cout << ans;
            br;
            return;
        }
    }
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