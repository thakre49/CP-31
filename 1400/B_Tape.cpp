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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> tapes;
    for (int i = 0; i < n - 1; i++)
    {
        tapes.push_back(nums[i + 1] - nums[i] - 1);
    }
    sort(tapes.begin(), tapes.end());

    int ans = n;
    int i = 0;
    while (i < n - k)
    {
        ans += tapes[i];
        i++;
    }

    cout << ans;
    br;
}

int main()
{

    solve();

    return 0;
}