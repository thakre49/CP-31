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
    string s;
    cin >> s;
    long long totalW = 0;
    int n = s.length();
    int tempV = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            totalW += max(0, tempV - 1);
            tempV = 0;
        }
        else
        {
            tempV++;
        }
    }
    totalW += max(0, tempV - 1);
    long long ans = 0;
    tempV = 0;
    long long wTillI = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            wTillI += max(0, tempV - 1);
            ans += (wTillI * (totalW - wTillI));
            tempV = 0;
        }
        else
        {
            tempV++;
        }
    }

    cout << ans;
    br;
}

int main()
{
    solve();

    return 0;
}