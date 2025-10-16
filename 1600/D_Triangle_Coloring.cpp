#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;

// Constants
const int mod = 998244353;

// Fast exponentiation for modular inverse
long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

// Function to compute factorial modulo MOD
long long fact(long long n)
{
    long long res = 1;
    for (long long i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

// Function to compute nCr % mod
long long nCr(long long n, long long r)
{
    if (r < 0 || r > n)
        return 0;
    vector<long long> factArr(n + 1), invFact(n + 1);
    factArr[0] = 1;
    for (int i = 1; i <= n; i++)
        factArr[i] = (factArr[i - 1] * i) % mod;
    invFact[n] = power(factArr[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;

    return (((factArr[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++)
        cin >> edges[i];

    int t = n / 3; // number of triangles
    long long ans = 1;

    // Correct per-triangle calculation
    for (int i = 0; i < n; i += 3)
    {
        int a = edges[i];
        int b = edges[i + 1];
        int c = edges[i + 2];

        int s1 = a + b; // vertex1 alone
        int s2 = a + c; // vertex2 alone
        int s3 = b + c; // vertex3 alone

        int mx = max(s1, max(s2, s3));
        int cnt = 0;
        if (s1 == mx)
            cnt++;
        if (s2 == mx)
            cnt++;
        if (s3 == mx)
            cnt++;
        // cout << cnt << endl;
        ans = (ans * cnt) % mod;
    }

    // Multiply by C(t, t/2)
    ans = (ans * nCr(t, t / 2)) % mod;

    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
