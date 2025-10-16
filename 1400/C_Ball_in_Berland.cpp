
#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    vector<pair<int, int>> liked(k);
    vector<int> b1(k);
    vector<int> g1(k);
    for (int i = 0; i < k; i++)
    {
        cin >> b1[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> g1[i];
    }
    for (int i = 0; i < k; i++)
    {
        liked[i] = {b1[i], g1[i]};
    }
    vector<int> boyCount(a + 1);
    vector<int> girlCount(b + 1);
    map<pair<int, int>, int> pairCount;
    for (int i = 0; i < k; i++)
    {
        boyCount[liked[i].first]++;
        girlCount[liked[i].second]++;
        pairCount[{liked[i].first, liked[i].second}]++;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = ans + (k - boyCount[liked[i].first] - girlCount[liked[i].second] + pairCount[{liked[i].first, liked[i].second}]);
    }
    cout << ans / 2;
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