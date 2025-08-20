#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> setbits;
    vector<vector<int>> nums(n);

    for (int i = 0; i < n; i++)
    {
        int total;
        cin >> total;
        nums[i].resize(total);
        for (int j = 0; j < total; j++)
        {
            cin >> nums[i][j];
            setbits[nums[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int bit : nums[i])
        {
            if (setbits[bit] < 2)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
