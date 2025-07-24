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
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j] == '0' ? 0 : 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < (n - i - 1); j++)
        {
            int zeros = 0;
            int ones = 0;
            if (grid[i][j] == 0)
                zeros++;
            else
                ones++;
            if (grid[j][n - 1 - i] == 0)
                zeros++;
            else
                ones++;
            if (grid[n - 1 - i][n - 1 - j] == 0)
                zeros++;
            else
                ones++;
            if (grid[n - 1 - j][i] == 0)
                zeros++;
            else
                ones++;

            ans += min(zeros, ones);
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