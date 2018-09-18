#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin >> n;
    vector<vector<ll>> memo;
    memo.resize(n+1, vector<ll>(n+1, 0));
    memo[0][0] = 1;

    for(ll i = 0; i < n; i++) {
        char op;
        cin >> op;

        if(op == 'f') {
            memo[i+1][0] = 0;
            for(ll j = 1; j <= n; j++) {
                memo[i+1][j] = memo[i][j-1];
                memo[i+1][j] %= mod;
            }
        }

        if(op == 's') {
            ll sum = 0;
            for(ll j = n-1; j >= 0; j--) {
                sum += memo[i][j];
                sum %= mod;

                memo[i+1][j] = sum;
                memo[i+1][j] %= mod;
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans += memo[n-1][i];
        ans %= mod;
    }

    cout << ans << endl;
}


