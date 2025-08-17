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
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    ll sum = 0; // long long to avoid overflow
    for (int i = 0; i < k; i++)
        sum += nums[i];

    int i = 0;
    int j = k - 1;

    lld overallSum = 0; // long double for high precision

    while (j < n)
    {
        overallSum += sum;
        sum -= nums[i];
        i++;
        j++;
        if (j < n)
            sum += nums[j];
    }

    cout << fixed << setprecision(6) << (overallSum / (n - k + 1));
    br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
