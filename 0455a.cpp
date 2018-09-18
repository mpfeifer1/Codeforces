#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> v(100001, 0);
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v[temp]++;
    }

    vector<ll> memo(100001, 0);
    memo[0] = 0;
    memo[1] = v[1];

    for(ll i = 2; i <= 100001; i++) {
        memo[i] = max(memo[i-1], memo[i-2] + v[i] * i);
    }

    cout << memo[100000] << endl;
}
