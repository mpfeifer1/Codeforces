#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll big = 100000;
ll mod = 1000000007;

int main() {
    ll t, k;
    cin >> t >> k;

    vector<ll> ways(big+1, 0);
    ways[0] = 1;

    for(ll i = 1; i <= big; i++) {
        ways[i] += ways[i-1];
        ways[i] %= mod;
        if(i-k >= 0) {
            ways[i] += ways[i-k];
            ways[i] %= mod;
        }
    }

    vector<ll> memo(big+1, 0);
    memo[0] = 1;
    for(ll i = 1; i <= big; i++) {
        memo[i] = memo[i-1] + ways[i];
        memo[i] %= mod;
    }

    for(int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;

        ll ans = memo[b] - memo[a-1];
        ans %= mod;
        if(ans < 0) {
            ans += mod;
        }
        ans %= mod;

        cout << ans << endl;
    }
}
