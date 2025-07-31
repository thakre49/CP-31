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
    int n, s;
    cin >> n >> s;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int i = 0, sum = 0, ans = 0;

    for (int j = 0; j < n; j++)
    {
        sum += nums[j];

        while (sum > s && i <= j)
        {
            sum -= nums[i];
            i++;
        }

        if (sum == s)
        {
            ans = max(ans, j - i + 1);
        }
    }

    if (ans == 0)
        cout << -1 << "\n"; // No such subarray exists
    else
        cout << n - ans << "\n"; // Minimum elements to remove
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

/*

longest subarray with sum s is k
ans = n - k


*/