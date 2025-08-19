#include <bits/stdc++.h>
using namespace std;

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

    vector<int> ans(n, 1);
    int j = n - 1;
    int i = n - 1;
    int fact = 1;
    while (j >= 0 && i >= 0)
    {
        if (nums[i] >= fact) /**/
        {
            fact++;
            i--;
        }
        else
        {
            ans[j] = j - i;
            j--;
            fact--;
        }
    }
    while (j >= 0)
    {
        ans[j] = j - i;
        j--;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
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