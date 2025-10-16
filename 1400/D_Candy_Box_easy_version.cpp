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
        cin >> nums[i];

    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
        freq[nums[i]]++;

    sort(freq.begin(), freq.end(), greater<int>());

    int current = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << freq[i] << " ";
        int temp = min(current, freq[i]);
        ans += temp;
        current = max(0, temp - 1);
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