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
    int n, w;
    cin >> n >> w;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }
    int ans = 0;

    int fullOccupied = INT_MAX;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & w)
        {
            fullOccupied = min(fullOccupied, m[(1 << i)]);
        }
    }
    ans += fullOccupied;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & w)
        {
            m[(1 << i)] -= fullOccupied;
        }
    }
    // 1 2 4  8 8
    int temp = 0;
    for (auto it : m)
    {
        for (int i = 0; i < it.second; i++)
        {
            if (temp + it.first <= w)
            {
                temp += it.first;
            }
            else
            {
                ans++;
                temp = it.first;
            }
        }
    }
    if (temp)
        ans++;
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
/*


10 ->   1 0 1 0
        3 0 3 0



*/