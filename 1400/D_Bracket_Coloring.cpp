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
    vector<int> ans(n);
    int count = 0;
    int countO = 0;
    int countC = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            countC++;
        }
        else
            countO++;
    }

    if (countO != countC)
    {
        cout << -1;
        br;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            count--;
        }
        else
        {
            count++;
           
        }
    }
    int col = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            col++;
            break;
        }
    }
    if (col > 1)
        cout << 2;
    else
        cout << 1;
    br;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
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