#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll find(vector<ll>& d, ll a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<ll>& d, ll a, ll b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> d(n+1, -1);
    for(ll i = 1; i <= n; i++) {
        ll n;
        cin >> n;

        join(d, i, n);
    }

    unordered_map<ll,ll> m;

    for(ll i = 1; i <= n; i++) {
        m[find(d, i)]++;
    }

    vector<ll> sizes;
    for(auto i : m) {
        sizes.push_back(i.second);
    }

    sort(sizes.begin(), sizes.end());

    if(sizes.size() > 1) {
        ll t = sizes.back();
        sizes.pop_back();
        sizes.back() += t;
    }

    ll total = 0;
    for(auto i : sizes) {
        total += i * i;
    }

    cout << total << endl;
}
