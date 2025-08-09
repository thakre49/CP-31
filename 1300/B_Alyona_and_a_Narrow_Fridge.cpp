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

bool isPossible(int k, int h, vector<int> &temp)
{

    vector<int> nums(temp.begin(), temp.begin() + k);

    // Sort in descending order
    sort(nums.begin(), nums.end());
    int i = k - 1;
    while (i >= 0)
    {
        if (nums[i] <= h && i - 1 >= 0)
        {
            h -= nums[i];
            i = i - 2;
        }
        else if (nums[i] <= h)
        {
            h -= nums[i];
            i = i - 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, h;
    cin >> n >> h;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int low = 1;
    int high = n;
    int ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(mid, h, nums))
        {
            ans = max(mid, ans);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans;
    br;
}

int main()
{

    solve();

    return 0;
}