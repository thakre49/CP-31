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

void solve()
{
    int n, m;
    cin >> n >> m;
    int num = n;
    int count2 = 0;
    while (num)
    {
        if (num % 2 == 0)
        {
            count2++;
            num = num / 2;
        }
        else
            break;
    }
    int count5 = 0;
    while (num)
    {
        if (num % 5 == 0)
        {
            count5++;
            num = num / 5;
        }
        else
            break;
    }

    int req5 = count2 - min(count2, count5);
    int req2 = count5 - min(count2, count5);

    long long ans = 1;
    while (ans <= m)
    {
        if (req5 && ans * 5 <= m)
        {
            ans = ans * 5;
            req5--;
        }
        else if (req2 && ans * 2 <= m)
        {
            ans = ans * 2;
            req2--;
        }
        else if (ans * 10 <= m)
        {
            ans = ans * 10;
        }
        else
            break;
    }

    for (int i = 9; i >= 2; i--)
    {
        if (ans * i <= m)
        {
            ans = ans * i;
            break;
        }
    }
    long long finalAns = ans * n;
    cout << finalAns;
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