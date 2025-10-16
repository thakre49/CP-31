#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (ll)4e18;  // something larger than any possible result

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // compute minimum initial value and minimum adjacent difference
        ll current_min = a[0];
        ll min_adj_diff = INFLL;
        for(int i = 1; i < n; i++){
            ll diff = a[i] - a[i-1];
            if(diff < min_adj_diff) min_adj_diff = diff;
        }

        // If we do zero operations, the answer is current_min
        ll ans = current_min;

        if(k == 0){
            // problem statement doesn't explicitly mention k=0 but if allowed
            // just output current min
            cout << ans << "\n";
            continue;
        }

        if(k >= 3){
            // editorial: answer is zero
            cout << 0 << "\n";
            continue;
        }

        if(k == 1){
            // One operation: either do nothing, or pick one pair and append diff
            // So minimum possible = min(current_min, min_adj_diff)
            ans = min(ans, min_adj_diff);
            cout << ans << "\n";
            continue;
        }

        // k == 2
        // Start with ans among no operation or one operation
        ans = min(ans, min_adj_diff);

        // Now try all pairs for first operation
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ll v = a[j] - a[i];
                // you can consider the new element v
                // and compare any existing a[x] with v (i.e. second op or just check v itself)
                // find closest to v in array a

                // binary search
                auto it = lower_bound(a.begin(), a.end(), v);
                if(it != a.end()){
                    ll candidate = *it;
                    ll diff2 = llabs(candidate - v);
                    if(diff2 < ans) ans = diff2;
                }
                if(it != a.begin()){
                    --it;
                    ll candidate = *it;
                    ll diff2 = llabs(candidate - v);
                    if(diff2 < ans) ans = diff2;
                }
                // also consider just using v alone (if that's smaller than ans)
                if(v < ans) ans = v;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
