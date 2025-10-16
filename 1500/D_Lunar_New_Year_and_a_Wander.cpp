#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while (!pq.empty())
    {
        int node = pq.top();
        cout << node << " ";
        pq.pop();

        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                visited[child] = true;
                pq.push(child);
            }
        }
    }
    return 0;
}