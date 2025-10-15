#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = k; i < n; ++i)
    {
        if (s[i] == '1')
        {
            if (s[i % k] == '0')
            {
                cout << "NO\n";
                return;
            }
            s[i % k] = '1';
        }
        else if (s[i] == '0')
        {
            if (s[i % k] == '1')
            {
                cout << "NO\n";
                return;
            }
            s[i % k] = '0';
        }
    }

    int c1 = 0, c0 = 0;
    for (int i = 0; i < k; ++i)
    {
        if (s[i] == '1')
            ++c1;
        if (s[i] == '0')
            ++c0;
    }

    if (c1 > k / 2 || c0 > k / 2)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int32_t main()
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
