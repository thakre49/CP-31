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

pair<int, int> recurr(int node, vector<vector<int>> &adj, string &colors, int &ans)
{

    int subtreeW = 0;
    int subtreeB = 0;

    for (auto child : adj[node])
    {
        auto temp = recurr(child, adj, colors, ans);
        subtreeW += temp.first;
        subtreeB += temp.second;
    }

    if (colors[node - 1] == 'W')
        subtreeW++;
    else
        subtreeB++;

    ans += (subtreeB == subtreeW);

    return {subtreeW, subtreeB};
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }

    string colors;
    cin >> colors;
    int ans = 0;
    auto funReturn = recurr(1, adj, colors, ans);
    //cout << funReturn.first << " " << funReturn.second;
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