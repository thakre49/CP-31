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
    long long ans = 0;
    vector<int> removed(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (removed[i + 1] == 1 || s[i] == '0')
            for (int j = i + 1; j <= n; j = j + i + 1)
            {
                if (s[j - 1] == '0')
                {
                    ans += (i + 1);

                    s[j - 1] = 1;
                    removed[j] = 1;
                }
                else if (removed[j] == 0)
                {
                    break;
                }
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
