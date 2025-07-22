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
    int n, m;
    cin >> n >> m;
    vector<int> nums(n, 0);
    vector<int> remainders(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        remainders[nums[i] % m]++;
    }
    int ans = remainders[0] > 0 ? 1 : 0;
    for (int i = 1; i <= m / 2; i++)
    {
        int freqNum = remainders[i];
        int freqNumPair = remainders[m - i];
        if (freqNum == 0 && freqNumPair == 0)
            continue;

        if (i == m - i && freqNum != 0)
        {
            ans++;
        }
        else if (i != m - i)
        {
            ans++;
            ans += max(0, (max(freqNum, freqNumPair) - min(freqNum, freqNumPair) - 1));
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