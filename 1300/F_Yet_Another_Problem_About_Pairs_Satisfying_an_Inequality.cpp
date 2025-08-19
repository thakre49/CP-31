/*

num   1 2 3 2 1 4
ind   2 3 4 6 7 8

1 1 2 2 3 4
2 7 3 6 4 8

2,4
2,8
3,8

(2,3,4,6,7,8)

ai < i < aj < j


*/

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

int binarySearchForAnswer(int low, int high, int num, vector<pair<int, int>> &nums)
{
    int n = nums.size();
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid].first > num)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return n - ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> nums;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (i > temp)
            nums.push_back({temp, i});
    }
    int finalRange = nums.size();

    if (finalRange < 2)
    {
        cout << 0;
        br;
        return;
    }
    sort(nums.begin(), nums.end());

    long long ans = 0;

    for (int i = 0; i < finalRange - 1; i++)
    {
        ans += binarySearchForAnswer(i, finalRange - 1, nums[i].second, nums);
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