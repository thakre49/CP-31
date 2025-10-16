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
    vector<int> beauty(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> beauty[i];
    }

    map<int, vector<int>> val;
    for (int i = 1; i <= n; i++)
    {
        val[beauty[i] - i].push_back(beauty[i]);
    }

    long long ans = 0;
    for (auto it : val)
    {
        long long temp = 0;
        for (int num : it.second)
        {
            temp += num;
        }
        ans = max(ans, temp);
    }

    cout << ans;
    br;
}

int main()
{
    solve();

    return 0;
}