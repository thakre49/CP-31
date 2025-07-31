#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> nums(n, 0);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    long long ans = 1;
    long long i = 0;

    vector<long long> gaps;
    while (i < n - 1)
    {
        if (nums[i + 1] - nums[i] <= x)
        {
            i++;
        }
        else
        {
            ans++;

            long long gap = nums[i + 1] - nums[i];
            if (gap)
            {
                gaps.push_back(gap);
            }

            i++;
        }
    }

    sort(gaps.begin(), gaps.end());

    for (long long i = 0; i < gaps.size(); i++)
    {
        long long kNeeded = (gaps[i] % x == 0) ? gaps[i] / x : (gaps[i] / x) + 1;
        kNeeded--;
        if (kNeeded <= k)
        {
            ans--;
            k -= kNeeded;
        }
        else
        {
            break;
        }
    }

    cout << ans;
}

int main()
{
    solve();
    return 0;
}
