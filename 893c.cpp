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
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    vector<ll> d(n, -1);

    for(auto& i : v) {
        cin >> i;
    }

    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        join(d, n1, n2);
    }

    unordered_map<ll, ll> s;

    for(ll i = 0; i < n; i++) {
        ll par = find(d, i);
        if(s.count(par) == 0) {
            s[par] = v[i];
        }

        s[par] = min(s[par], v[i]);
    }

    ll total = 0;
    for(auto i : s) {
        total += i.second;
    }

    cout << total << endl;
}
