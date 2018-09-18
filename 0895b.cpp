#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, x, k;
    cin >> n >> x >> k;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());
    vector<ll>::iterator u, d;

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ll hi, lo;
        if(v[i] % x == 0) {
            lo = max(v[i], v[i] + (x*(k-1) - (v[i]%x)));
            hi = v[i] + (x * k - (v[i] % x));
        }
        else {
            lo = max(v[i], v[i] + (x * k - (v[i]%x)));
            hi = v[i] + (x * (k+1) - (v[i] % x));
        }

        d = lower_bound(v.begin(), v.end(), lo);
        u = lower_bound(v.begin(), v.end(), hi);

        ans += (u - v.begin()) - (d - v.begin());
    }

    cout << ans << endl;
}
