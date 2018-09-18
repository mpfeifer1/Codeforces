#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 62;
ll mod = 1000000007;

void dfs1(vector<vector<ll>>& adj, unordered_set<ll>& vis, stack<ll>& r, ll curr) {
    if(vis.count(curr) > 0) {
        return;
    }
    vis.insert(curr);

    for(auto i : adj[curr]) {
        dfs1(adj, vis, r, i);
    }

    r.push(curr);
}

void dfs2(vector<vector<ll>>& adj, unordered_set<ll>& vis, vector<ll>& here, ll curr) {
    if(vis.count(curr) > 0) {
        return;
    }
    vis.insert(curr);
    here.push_back(curr);

    for(auto i : adj[curr]) {
        dfs2(adj, vis, here, i);
    }
}

int main() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    ll m;
    cin >> m;

    vector<vector<ll>> adj1(n);
    vector<vector<ll>> adj2(n);
    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        adj1[n1].push_back(n2);
        adj2[n2].push_back(n1);
    }

    unordered_set<ll> vis;
    stack<ll> r;

    for(ll i = 0; i < n; i++) {
        if(vis.count(i) > 0) {
            continue;
        }

        dfs1(adj1, vis, r, i);
    }

    ll ways = 1;
    ll cost = 0;
    vis.clear();
    while(!r.empty()) {
        ll curr = r.top();
        r.pop();

        if(vis.count(curr) == 0) {
            vector<ll> here;
            dfs2(adj2, vis, here, curr);

            ll best = inf;
            ll freq = 0;
            for(auto i : here) {
                if(v[i] < best) {
                    best = v[i];
                    freq = 1;
                }
                else if(v[i] == best) {
                    freq++;
                }
            }

            ways *= freq;
            ways %= mod;
            cost += best;
        }
    }

    cout << cost << " " << ways << endl;
}
