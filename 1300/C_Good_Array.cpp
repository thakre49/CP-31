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
    vector<int> freq(1000000 + 2, 0);
    vector<int> nums(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
        sum += nums[i];
    }

    int count = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        long long reqNum = sum - nums[i];
        if (reqNum % 2)
            continue;

        if (reqNum / 2 == nums[i])
        {
            if ((reqNum / 2 <= 1000000) && freq[nums[i]] >= 2)
            {
                count++;
                ans.push_back(i + 1);
            }
        }
        else
        {
            if ((reqNum / 2 <= 1000000) && (freq[reqNum / 2] >= 1))
            {

                count++;
                ans.push_back(i + 1);
            }
        }
    }
    cout << count;
    br;
    for (int a : ans)
    {
        cout << a << " ";
    }
    br;
}

int main()
{

    solve();

    return 0;
}