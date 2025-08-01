#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using pii = pair<int, int>;

// Main logic for a single test case
void solve()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // Frequency map: pair<mod_x, mod_y> -> count
    map<pii, int> freq;

    ll count = 0;

    // Traverse from end to start
    for (int i = n - 1; i >= 0; --i)
    {
        int modx = a[i] % x;
        int mody = a[i] % y;

        int needx = (x - modx) % x;
        int needy = mody;

        count += freq[{needx, needy}];

        // Store current pair for future matches
        freq[{modx, mody}]++;
    }

    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
