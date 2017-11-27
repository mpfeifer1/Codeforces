#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    vector<ll> deg(n, 0);
    vector<ll> dist(n, 1);

    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        deg[n1]++;
        deg[n2]++;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for(ll i = 0; i < n; i++) {
        for(auto j : adj[i]) {
            if(j < i) {
                dist[i] = max(dist[i], dist[j]+1);
            }
        }
    }

    ll best = 0;
    for(ll i = 0; i < n; i++) {
        best = max(best, deg[i] * dist[i]);
    }

    cout << best << endl;
}
