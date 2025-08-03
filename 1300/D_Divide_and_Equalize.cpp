#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
vector<int> spf(MAX);

// Precompute smallest prime factor
void computeSPF()
{
    for (int i = 2; i < MAX; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAX; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Factorize a number using SPF
unordered_map<int, int> factorize(int x)
{
    unordered_map<int, int> factors;
    while (x > 1)
    {
        int p = spf[x];
        while (x % p == 0)
        {
            factors[p]++;
            x /= p;
        }
    }
    return factors;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, long long> totalPrimeCount;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        unordered_map<int, int> factors = factorize(a[i]);
        for (unordered_map<int, int>::iterator it = factors.begin(); it != factors.end(); ++it)
        {
            totalPrimeCount[it->first] += it->second;
        }
    }

    for (unordered_map<int, long long>::iterator it = totalPrimeCount.begin(); it != totalPrimeCount.end(); ++it)
    {
        if (it->second % n != 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computeSPF();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
