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
    char c;
    cin >> c;
    string s;
    cin >> s;
    int even = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 && s[i - 1] != c)
            odd++;
        else if (i % 2 == 0 && s[i - 1] != c)
            even++;
    }

    if (even != 0 && odd != 0)
    {
        cout << 2;
        br;
        cout << 2 << " " << 3;
        br;
    }
    else if (even != 0 && odd == 0)
    {
        cout << 1;
        br;
        cout << 3;
        br;
    }
    else if (even == 0 && odd != 0)
    {
        cout << 1;
        br;
        cout << 2;
        br;
    }
    else
    {
        cout << 0;
        br;
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