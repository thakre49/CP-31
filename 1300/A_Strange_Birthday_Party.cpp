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
    int n, m;
    cin >> n >> m;
    vector<int> friends(n + 1);
    vector<int> presents(m + 1);
    vector<int> freq(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> friends[i];
        freq[friends[i]]++;
    }
    for (int j = 1; j <= m; j++)
        cin >> presents[j];

    int i = 1;
    int j = m;
    long long ans = 0;
    while (j >= 1)
    {
        for (int ind = 0; ind < freq[j]; ind++)
        {
            if (presents[j] <= presents[i])
            {
                ans += presents[j];
            }
            else
            {
                ans += presents[i];
                i++;
            }
        }
        j--;
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