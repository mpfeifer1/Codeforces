#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 60;

ll process(vector<ll>& cost, ll plan) {
    ll total = 0;

    ll mask = 1;
    for(int i = 0; i < cost.size(); i++) {
        if(mask & plan) {
            total += cost[i];
        }

        mask <<= 1;
    }

    return total;
}

int main() {
    ll n, l;
    cin >> n >> l;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    for(ll i = 1; i < n; i++) {
        v[i] = min(v[i], 2*v[i-1]);
    }

    ll cost = 0;
    ll maxsize = pow((ll)2, n-1);
    cost += l / maxsize * v[n-1];
    l %= maxsize;

    ll mask = 1;
    ll ans = process(v, l);
    for(ll i = 0; i < n-1; i++, mask <<= 1) {
        if((mask & l) == 0) {
            continue;
        }

        l += mask;
        ans = min(ans, process(v, l));
    }

    cout << cost + ans << endl;
}
