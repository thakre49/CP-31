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
    vector<int> inTime(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int car;
        cin >> car;
        inTime[car] = i;
    }

    vector<int> outTime(n);

    for (int i = 0; i < n; i++)
    {
        cin >> outTime[i];
    }

    int ans = 0;

    int intTimeMin = n + 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (intTimeMin < inTime[outTime[i]])
        {
            ans++;
        }
        intTimeMin = min(intTimeMin, inTime[outTime[i]]);
    }
    cout << ans;
    br;
}

int main()
{
    solve();
    return 0;
}