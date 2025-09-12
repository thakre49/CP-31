#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    long long n;
    cin >> n;
    long long ans = 0;
    ans += n;
    for (int i = 1; i <= 63; i++)
    {
        long long num = (1LL << i);
        long long fullCount = n / num;
        long long halfCount = (n % num) ? 1 : 0;

        ans += (fullCount / 2) * 2;
        if ((halfCount > 0) && ((fullCount + halfCount) % 2 == 0))
            ans++;
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
