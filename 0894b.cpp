#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll fastpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while(exp > 0) {
        if((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll mod = 1000000007;

    ll ans = fastpow(2, (a-1), mod);
    ans = fastpow(ans, (b-1), mod);

    if((a+b) % 2 == 1 && c == -1) {
        ans = 0;
    }

    cout << ans % mod << endl;
}
