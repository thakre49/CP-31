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

    bool ans0 = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            ans0 = false;
            break;
        }
    }

    if (ans0)
    {
        cout << 0;
        br;
        return;
    }

    int ans1 = -1;

    for (int i = 2; i <= n; i++)
    {
        bool pos = true;
        for (int j = i; j <= n; j = j + i)
        {
            if (s[j - 1] != c)
            {
                pos = false;
                break;
            }
        }
        if (pos)
        {
            ans1 = i;
            break;
        }
    }

    if (ans1 != -1)
    {
        cout << 1;
        br;
        cout << ans1;
        br;
        return;
    }
    else
    {
        cout << 2;
        br;
        cout << n << " " << n - 1;
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