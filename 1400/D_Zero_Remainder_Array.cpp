#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        map<long long, long long> mp; // <-- changed

        for (int i = 0; i < n; i++)
        {
            long long r = a[i] % k;
            if (r == 0)
                continue; // already divisible
            long long need = (k - r) % k;
            mp[need]++;
        }

        long long ans = 0;
        for (auto &p : mp)
        {
            long long d = p.first;
            long long c = p.second;
            long long last = d + (c - 1) * k + 1;
            ans = max(ans, last);
        }

        cout << ans << "\n";
    }

    return 0;
}
