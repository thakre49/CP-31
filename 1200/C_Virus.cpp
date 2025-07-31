#include <bits/stdc++.h>
using namespace std;

// 7
// 5
// 11
// 28
// 9
// 5
// 2
// 15

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> infected(m);
    for (int i = 0; i < m; i++)
    {
        cin >> infected[i];
    }
    sort(infected.begin(), infected.end());
    vector<int> gaps;
    for (int i = 0; i < m - 1; i++)
    {
        if (infected[i + 1] - infected[i] - 1 > 0)
            gaps.push_back(infected[i + 1] - infected[i] - 1);
    }
    if (n - infected[m - 1] + infected[0] - 1 > 0)
        gaps.push_back(n - infected[m - 1] + infected[0] - 1);
    sort(gaps.begin(), gaps.end(), greater<int>());

    int ans = 0;
    int passInfected = 0;

    for (int i = 0; i < gaps.size(); i++)
    {

        if (gaps[i] - passInfected > 0)
        {
            if (gaps[i] - passInfected == 1)
            {
                ans += passInfected;
                passInfected += 2;
            }
            else if (gaps[i] - passInfected == 2)
            {
                ans += passInfected;
                passInfected += 2;
                ans++;
            }
            else
            {
                ans++;
                ans += passInfected;
                passInfected += 4;
            }
        }
        else
        {
            ans += gaps[i];
            passInfected += 4;
        }
    }
    cout << ans + infected.size() << endl;
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
