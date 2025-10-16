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
    vector<pair<int, int>> w(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int weight;
        cin >> weight;
        w[i] = {weight, i};
        sum += weight;
    }

    sort(w.begin() + 1, w.end(), greater<pair<int, int>>());

    vector<int> freq(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        freq[u]++;
        freq[v]++;
    }
    cout << sum << " ";

    int s = 1;
    int k = 2;
    while (k <= n - 1 || s <= n)
    {
        if (freq[w[s].second] >= 2)
        {
            sum += w[s].first;
            k++;
            freq[w[s].second]--;
            cout << sum << " ";
        }
        else
        {
            s++;
        }
    }
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