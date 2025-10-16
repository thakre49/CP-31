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
    int n = s.length();

    ll temp = 0;
    ll tempAns = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            tempAns = (tempAns * (temp + 1)) % mod;
            temp = 0;
        }
        else if (s[i] == 'a')
        {
            temp++;
        }
    }

    tempAns = (tempAns * (temp + 1)) % mod;

    cout << (tempAns - 1 + mod) % mod; // ensure non-negative
    br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
