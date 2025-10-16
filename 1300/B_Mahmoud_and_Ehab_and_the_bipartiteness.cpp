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

void count1(int node, int color, int par, vector<vector<int>> &adj, int &ans)
{
    if (color == 1)
        ans++;

    for (auto child : adj[node])
    {
        if (child != par)
            count1(child, 1 - color, node, adj, ans);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int whites = 0;

    count1(1, 1, 0, adj, whites);
    long long blacks = n - whites;

    long long ans = whites * blacks - (n - 1);
    cout << ans;
    br;
}

int main()
{

    solve();

    return 0;
}

/*
          1
        2
    3
  4
5


*/