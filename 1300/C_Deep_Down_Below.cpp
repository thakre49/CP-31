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

    vector<pair<int, int>> entryTotal;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int requiredPower = 0;
        for (int j = 0; j < k; j++)
        {
            int num;
            cin >> num;
            requiredPower = max(requiredPower, num - j);
        }
        entryTotal.push_back({requiredPower + 1, k}); // +1 as power must be > armor
    }

    sort(entryTotal.begin(), entryTotal.end());
    long long currentPower = 0;
    for (int i = 0; i < entryTotal.size(); i++)
    {
        long long requiredPower = entryTotal[i].first;
        if (requiredPower > currentPower)
        {
            ans += (requiredPower - currentPower);
            currentPower = requiredPower;
        }
        currentPower += entryTotal[i].second;
    }
    cout << ans;
    br;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}