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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int totalDigits = 0;
    vector<int> zeros;

    for (int num : nums)
    {
        int currentZ = 0;
        bool found = false;
        while (num)
        {
            int digit = num % 10;
            if (digit == 0 && !found)
                currentZ++;
            else
                found = true;
            totalDigits++;
            num = num / 10;
        }
        if (currentZ)
            zeros.push_back(currentZ);
    }

    sort(zeros.begin(), zeros.end(), greater<int>());
    for (int i = 0; i < zeros.size(); i = i + 2)
    {
        totalDigits -= zeros[i];
    }

    if (totalDigits >= m + 1)
        cout << "Sasha";
    else
        cout << "Anna";
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

5 4 4 4 3 3

anna = 5 4 3
sasha = 4 4 3



*/