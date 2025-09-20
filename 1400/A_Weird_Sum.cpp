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
    int col;
    unordered_map<int, vector<vector<int>>> grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> col;
            if (grid.find(col) == grid.end())
            {
                grid[col].push_back({});
                grid[col].push_back({});
            }

            grid[col][0].push_back(i + 1);
            grid[col][1].push_back(j + 1);
        }
    }
    long long ans = 0;
    for (auto &it : grid)
    {
        sort(it.second[0].begin(), it.second[0].end());
        sort(it.second[1].begin(), it.second[1].end());
        long long temp = 0;
        for (int i = 0; i < it.second[0].size(); i++)
        {
            temp += it.second[0][i];
            long long curr = abs((long long)(i + 1) * it.second[0][i] - temp);
            ans += curr;
        }
        temp = 0;
        for (int i = 0; i < it.second[1].size(); i++)
        {
            temp += it.second[1][i];
            long long curr = abs((long long)(i + 1) * it.second[1][i] - temp);
            ans += curr;
        }
    }
    cout << ans;
    br;
}

int main()
{
    solve();

    return 0;
}