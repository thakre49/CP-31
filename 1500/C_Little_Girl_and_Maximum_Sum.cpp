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
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> prefQ(n, 0);
    for (int i = 0; i < q; i++)
    {
        int start, end;
        cin >> start >> end;
        prefQ[start - 1]++;
        if (end < n)
            prefQ[end]--;
    }
    for (int i = 1; i < n; i++)
        prefQ[i] += prefQ[i - 1];
    sort(nums.begin(), nums.end());
    sort(prefQ.begin(), prefQ.end());

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans + (long long)nums[i] * prefQ[i];
    }
    cout << ans;
}

int main()
{
    solve();

    return 0;
}