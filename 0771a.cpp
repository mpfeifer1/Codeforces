#include <unordered_map>
#include <iostream>
#include <vector>

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

    vector<ll> d(n, -1);
    vector<ll> v(n, 0);

    // Read in input
    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        join(d, n1, n2);
        v[n1]++;
    }

    // First is nodes, second is edges
    unordered_map<ll, pair<ll, ll>> count;

    // See how big each connected component is
    for(ll i = 0; i < n; i++) {
        ll c = find(d, i);
        count[c].first++;
        count[c].second += v[i];
    }

    // Calculate if all are completely connected
    for(auto i : count) {
        ll nodes = i.second.first;
        ll edges = i.second.second;

        ll total = (nodes * (nodes - 1)) / 2;

        if(edges != total) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
