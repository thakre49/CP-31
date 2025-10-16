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
void count(int node, vector<vector<int>> &adj, int &ans, vector<int> &visited)
{
    if (!visited[node])
    {
        ans++;
        visited[node] = 1;
    }

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            count(it, adj, ans, visited);
        }
    }
}

void markAnswer(int node, int ans, vector<vector<int>> &adj,
                vector<int> &finalAns, vector<int> &visited)
{
    if (!visited[node])
    {
        finalAns[node] = ans;
        visited[node] = 1;
    }

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            markAnswer(it, ans, adj, finalAns, visited);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int groupSize;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> groupSize;
        vector<int> group(groupSize);
        for (int j = 0; j < groupSize; j++)
        {
            cin >> group[j];
        }
        for (int k = 0; k < groupSize - 1; k++)
        {
            adj[group[k]].push_back(group[k + 1]);
            adj[group[k + 1]].push_back(group[k]);
        }
    }

    vector<int> visited(n + 1, 0);
    vector<int> visited2(n + 1, 0);
    vector<int> answer(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int temp = 0;
            count(i, adj, temp, visited);
            markAnswer(i, temp, adj,
                       answer, visited2);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << " ";
    }
    br;
}

int main()
{
    solve();

    return 0;
}