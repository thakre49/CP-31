#include <bits/stdc++.h>
using namespace std;

int getMsbPosition(int n)
{
    int loc = 0;

    for (int i = 31; i >= 0; i--)
    {
        if ((1 << i) & n)
        {
            return i;
        }
    }

    return -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<long long> msbCount(31, 0);
    for (int i = 0; i < n; i++)
    {
        msbCount[getMsbPosition(nums[i])]++;
    }

    long long ans = 0;
    for (int i = 0; i < 31; i++)
    {
        if (msbCount[i] >= 2)
        {
            ans += (msbCount[i] * (msbCount[i] - 1)) / 2;
        }
    }

    cout << ans << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
