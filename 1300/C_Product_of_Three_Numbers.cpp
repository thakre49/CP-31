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

vector<int> primeFactors(long long n)
{
    vector<int> factors;

    // Handle 2 separately to skip even numbers later
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    // Check odd factors from 3 to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back((int)i);
            n /= i;
        }
    }

    // If n is still > 2, then it's prime
    if (n > 2)
        factors.push_back((int)n);

    return factors;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    int count = 0;
    vector<int> factors = primeFactors(n);
    if (factors.size() < 3)
    {
        cout << "No";
        br;
        return;
    }
    int i = 0;
    ans.push_back(factors[0]);
    i++;

    if (factors[1] != factors[0])
    {
        ans.push_back(factors[1]);
        i++;
    }
    else
    {
        ans.push_back(factors[1] * factors[2]);
        i = i + 2;
    }

    int num3 = 1;
    for (int j = i; j < factors.size(); j++)
    {
        num3 = num3 * factors[j];
    }

    if (num3 == 1 || num3 == ans[0] || num3 == ans[1])
    {
        cout << "NO";
        br;
        return;
    }
    ans.push_back(num3);
    cout << "YES";
    br;
    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << " ";
    }
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