#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        ll a, b;
        cin >> n >> a >> b;
        vector<ll> x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];

        ll ans = 0;
        ll cap = 0; // current capital position (starts at 0)
        for (int i = 0; i < n; ++i)
        {
            ll dist = x[i] - cap;
            ans += dist * b;     // cost to conquer city i from current capital
            int rem = n - i - 1; // remaining cities after i
            // move capital to x[i] iff moving is beneficial for remaining cities
            if (a < b * 1LL * rem)
            {
                ans += dist * a;
                cap = x[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
