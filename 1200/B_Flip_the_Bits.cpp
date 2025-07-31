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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> zeros(n, 0);
    if (a[0] == '0')
        zeros[0]++;

    for (int i = 1; i < n; i++)
    {
        zeros[i] = zeros[i - 1] + (a[i] == '0' ? 1 : 0);
    }

    int i = n - 1;
    while (i >= 0)
    {
        if (i >= 0 && a[i] != b[i])
        {
            int prev = i;
            while (i >= 0 && a[i] != b[i])
            {
                i--;
            }
            if (i < 0)
            {
                if ((prev % 2 == 0 || zeros[prev] != (prev + 1) / 2))
                {
                    cout << "NO";
                    br;
                    return;
                }
            }
            else if ((i % 2 == 0 || zeros[i] != (i + 1) / 2) || (prev % 2 == 0 || zeros[prev] != (prev + 1) / 2))
            {
                cout << "NO";
                br;
                return;
            }
        }
        else
        {
            i--;
        }
    }

    cout << "YES";
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