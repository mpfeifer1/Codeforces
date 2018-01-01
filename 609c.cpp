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

    ll avg = total / n;

    ll hi = total % n;
    ll lo = n - hi;

    ll cost = 0;
    for(auto i : v) {
        if(i > avg) {
            hi--;
            cost += abs((avg+1) - i);
        }
        if(i <= avg) {
            lo--;
            cost += abs(avg - i);
        }
    }

    while(lo < 0) {
        lo++;
        cost++;
    }
    while(hi < 0) {
        hi++;
        cost++;
    }

    cout << cost / 2 << endl;
}
