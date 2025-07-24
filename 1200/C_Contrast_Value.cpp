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
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (n == 1)
    {
        cout << 1;
        br;
        return;
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count++;
        }
    }
    if (count == n - 1)
    {
        cout << 1;
        br;
        return;
    }

    int ans = 1;
    int j = 1;
    int i = 0;
    int eqCount = 1;
    int mono = (nums[1] - nums[0]) >= 0 ? 1 : -1;

    while (j < n)
    {
        if ((nums[j] - nums[j - 1]) * mono >= 0)
        {

            if (nums[j] == nums[i])
                eqCount++;

            j++;
        }
        else
        {
            ans++;
            mono = mono * (-1);
            if (eqCount == j - 1 - i + 1)
            {
                ans--;
            }
            i = j - 1;
            eqCount = 1;
        }
    }

    ans++;
    cout << ans;
    br;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
