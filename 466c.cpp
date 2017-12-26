#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll total = 0;
    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
        total += i;
    }

    if(total % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    unordered_set<ll> lo;
    ll lo_total = 0;
    for(ll i = 0; i < n; i++) {
        lo_total += v[i];
        if(lo_total == total/3) {
            lo.insert(i+1);
        }
    }

    unordered_set<ll> hi;
    ll hi_total = 0;
    for(ll i = n-1; i >= 0; i--) {
        hi_total += v[i];
        if(hi_total == total/3) {
            hi.insert(i);
        }
    }

    total = 0;
    for(ll i = 0; i < 500005; i++) {
        hi.erase(i);
        if(lo.count(i) > 0) {
            total += hi.size();
        }
    }

    cout << total << endl;
}
