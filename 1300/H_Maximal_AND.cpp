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
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = 0;

    for (int i = 30; i >= 0; i--)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if ((nums[j] & (1 << i)) == 0)
            {
                temp++;
            }
        }
        if (temp <= k)
        {
            ans = ans ^ (1 << i);
            k -= temp;
        }
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

/*

k = 2
2 1 1

2 ->  1 0
1 ->  0 1
1 ->  0 1



*/