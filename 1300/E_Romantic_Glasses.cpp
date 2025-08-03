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
typedef map<int, int> mi;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    map<long long, int> m1;
    long long sum = 0;
    m1[sum] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            sum -= nums[i];
        else
            sum += nums[i];

        if (m1.count(sum))
        {
            cout << "YES";
            br;
            return;
        }

        m1[sum]++;
    }

    map<long long, int> m2;
    sum = 0;
    m2[sum] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            sum += nums[i];
        else
            sum -= nums[i];

        if (m2.count(sum))
        {
            cout << "YES";
            br;
            return;
        }

        m2[sum]++;
    }

    cout << "NO";
    br;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
