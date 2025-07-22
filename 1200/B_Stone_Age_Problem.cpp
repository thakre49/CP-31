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
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n + 1, 0); // Changed to ll
    vector<int> lastQueryChange(n + 1, -1);
    int lastallChangeQuery = -1;
    ll lastallChangeQueryNum = 0; // Changed to ll

    ll sum = 0; // Changed to ll
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int type;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            int index;
            ll newNum; // Changed to ll
            cin >> index >> newNum;

            if (lastallChangeQuery > lastQueryChange[index])
            {
                sum -= lastallChangeQueryNum;
                sum += newNum;
                nums[index] = newNum;
                lastQueryChange[index] = i;
            }
            else
            {
                sum -= nums[index];
                sum += newNum;
                nums[index] = newNum;
                lastQueryChange[index] = i;
            }
        }
        else
        {
            ll newNum; // Changed to ll
            cin >> newNum;
            sum = (ll)n * newNum;
            lastallChangeQuery = i;
            lastallChangeQueryNum = newNum;
        }

        cout << sum;
        br;
    }
}

int main()
{
    solve();
    return 0;
}
