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

bool isPossible(int k, int n, vector<pri> &segs)
{
    int jl = 0;
    int jr = 0;
    for (int i = 0; i < n; i++)
    {
        int l = segs[i].first;
        int r = segs[i].second;
        // on right
        if (l >= jl)
        {
            if (jr + k >= l)
            {
                jr = min(jr + k, r);
                jl = max(jl - k, l);
            }
            else
                return false;
        }
        // on left
        else if (l < jl)
        {
            if (jl - k <= r)
            {
                jl = max(jl - k, l);
                jr = min(jr + k, r);
            }
            else
                return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<pri> segs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> segs[i].first;
        cin >> segs[i].second;
    }
    int low = 0;
    int high = 1e9;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(mid, n, segs))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
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