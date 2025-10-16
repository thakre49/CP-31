#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> uni(n), skill(n);
    for (int i = 0; i < n; i++)
        cin >> uni[i];
    for (int i = 0; i < n; i++)
        cin >> skill[i];

    unordered_map<int, vector<ll>> m;
    for (int i = 0; i < n; i++)
        m[uni[i]].push_back(skill[i]);

    // Sort & prefix sum
    for (auto &team : m)
    {
        sort(team.second.begin(), team.second.end(), greater<>());
        for (int j = 1; j < (int)team.second.size(); j++)
            team.second[j] += team.second[j - 1];
    }

    vector<ll> ans(n + 1, 0);

    // Process each team
    for (auto &team : m)
    {
        int sz = team.second.size();
        for (int k = 1; k <= sz; k++)
        {
            int full = sz / k;
            if (full > 0)
            {
                ans[k] += team.second[full * k - 1];
            }
        }
    }

    for (int k = 1; k <= n; k++)
        cout << ans[k] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
