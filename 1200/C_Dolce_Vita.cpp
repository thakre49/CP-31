#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());

    ll sum = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        if (sum > x)
            break;

        ll days = (x - sum) / (i + 1) + 1;
        ans += days;
    }

    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
