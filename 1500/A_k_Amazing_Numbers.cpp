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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
        m[nums[i]].push_back(i);

    vector<int> ans(n + 1, -1);
    for (auto it : m)
    {
        int num = it.first;
        int temp = it.second[0];
        for (int i = 1; i < it.second.size(); i++)
        {
            temp = max(temp, it.second[i] - it.second[i - 1]);
        }
        temp = max(temp, n + 1 - it.second[it.second.size() - 1]);
        int st = temp;
        while (st <= n && ans[st] == -1)
        {
            ans[st] = num;
            st++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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