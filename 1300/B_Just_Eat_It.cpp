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
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    int i = 0;
    int j = 0;
    long long tempSum = 0;

    while (j < n)
    {
        tempSum += nums[j];

        if (tempSum >= sum && (j - i) < n - 1)
        {

            cout << "NO";
            br;
            return;
        }
        else if (tempSum <= 0)
        {

            while (tempSum <= 0 && i <= j)
            {
                tempSum -= nums[i];
                i++;
            }
            if (i == j && tempSum <= 0)
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        else
        {

            j++;
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