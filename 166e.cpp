#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;

    ll a = 0;
    ll b = 0;
    ll c = 0;
    ll d = 1;
    for(ll i = 0; i < n; i++) {
        ll a1, b1, c1, d1;

        a1 = b+c+d;
        b1 = a+c+d;
        c1 = a+b+d;
        d1 = a+b+c;

        a = a1;
        b = b1;
        c = c1;
        d = d1;

        a %= mod;
        b %= mod;
        c %= mod;
        d %= mod;
    }

    cout << d << endl;
}
