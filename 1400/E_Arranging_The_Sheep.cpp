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
    string s;
    cin >> s;

    ll totalCount = 0;
    ll totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            totalCount++;
            totalSum += (i + 1);
        }
    }
    ll leftSum = 0;
    ll leftCount = 0;
    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            ll leftAns = (i + 1) * leftCount - (leftCount * (leftCount + 1)) / 2 - leftSum;
            ll rightSum = totalSum - leftSum - (i + 1);
            ll rightCount = totalCount - leftCount - 1;
            ll rightAns = (rightSum) - (i + 1) * rightCount - (rightCount * (rightCount + 1)) / 2;

            ans = min(ans, leftAns + rightAns);
            leftSum += (i + 1);
            leftCount++;
        }
    }
    if (ans == 1e18)
        cout << 0;
    else
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