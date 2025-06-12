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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int currentMax = n;
    int currentMin = 1;

    int i = 0;
    int j = n - 1;

       while (i < j && currentMin < currentMax)
    {

        if ((nums[i] > currentMin) && (nums[i] < currentMax) && (nums[j] > currentMin) && (nums[j] < currentMax))
        {
            cout << i + 1 << " " << j + 1;
            br;
            return;
        }
        if (nums[i] == currentMax)
        {
            i++;
            currentMax--;
        }
        if (nums[i] == currentMin)
        {
            i++;
            currentMin++;
        }
        if (nums[j] == currentMax)
        {
            j--;
            currentMax--;
        }
        if (nums[j] == currentMin)
        {
            j--;
            currentMin++;
        }
    }

    if (i >= j)
    {
        cout << -1;
        br;
    }
    else
    {
        cout << i + 1 << " " << j + 1;
        br;
    }
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