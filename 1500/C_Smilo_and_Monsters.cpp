#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
        cin >> nums[i];

    long long i = 0;
    long long j = n - 1;
    long long x = 0;
    sort(nums.begin(), nums.end());
    long long ops = 0;

    while (i < j)
    {
        if (x == nums[j])
        {
            ops++;
            x = 0;
            j--;
        }
        else
        {
            if (nums[i] + x > nums[j])
            {
                nums[i] -= (nums[j] - x);
                ops += nums[j] - x;
                x = nums[j];
            }
            else
            {
                x += nums[i];
                ops += nums[i];
                i++;
            }
        }
    }

    if (i == j)
    {
        if ((nums[j] + x) % 2)
        {
            ops++;
            nums[j]--;
            if (nums[j] == 0)
            {
                cout << ops << "\n";
                return;
            }
        }
        long long pass = (nums[j] + x) / 2 - x;
        ops += pass + 1;
    }

    cout << ops << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
