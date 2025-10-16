#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    map<pair<int, int>, int> m;
    int alreadyZero = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
        {
            alreadyZero++;
            continue;
        }
        else if (a[i] == 0)
            continue;

        int g = __gcd(a[i], b[i]);
        int p = -b[i] / g;
        int q = a[i] / g;

        // Normalize the sign so denominator is always positive
        if (q < 0)
        {
            q = -q;
            p = -p;
        }

        m[{p, q}]++;
    }

    int ans = alreadyZero;
    for (auto &it : m)
    {
        ans = max(ans, it.second + alreadyZero);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
