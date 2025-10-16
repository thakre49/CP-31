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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<long long> diff(n);
    long long maxNum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        diff[i] = (long long)a[i] - b[i];
        maxNum = max(maxNum, diff[i]);
    }
    int count = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == maxNum)
        {
            count++;
            ans.push_back(i + 1);
        }
    }
    cout << count;
    br;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
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

/*
5 7 4
-2 -3 -6

7 10 10





*/