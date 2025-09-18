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

int ansFinal = 0;

//****************************************************************
void dfs(int node, int par, int parAns,
         vector<int> &orderInList,
         vector<vector<int>> &adj,
         map<pair<int, int>, int> &m)
{
    ansFinal = max(ansFinal, parAns); // always update

    for (auto it : adj[node])
    {
        if (it != par)
        {
            int edgeId = m[{node, it}];

            int nAns = parAns;
            if (edgeId < orderInList[node])
            { // if edge index is smaller → new scan
                nAns++;
            }

            orderInList[it] = edgeId;
            dfs(it, node, nAns, orderInList, adj, m);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int u, v;
    map<pair<int, int>, int> m;
    vector<int> orderInList(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        m[{u, v}] = i;
        m[{v, u}] = i;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0, 1, orderInList, adj, m);

    cout << ansFinal;
    br;
    ansFinal = 0;
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
