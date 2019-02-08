#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = (ll)1 << 60;
const ll MAXN = 10000 + 10;

struct edge {
    ll a, b, cap, cost, flow;
    ll back;
};

vector<edge> e;
vector<vector<ll>> g;

void addedge(ll a, ll b, ll cap, ll cost) {
    edge e1 = {a,b,cap,cost,0,(ll)g[b].size()};
    edge e2 = {b,a,0,-cost,0,(ll)g[a].size()};
    g[a].push_back((ll) e.size());
    e.push_back(e1);
    g[b].push_back((ll) e.size());
    e.push_back(e2);
}

ll n, s, t;
ll k;

// Returns {flow,cost}
pair<ll,ll> getflow() {
    ll flow = 0, cost = 0;
    while(flow < k) {
        vector<ll> id(n, 0);
        vector<ll> d(n, inf);
        vector<ll> q(n);
        vector<ll> p(n);
        vector<ll> p_edge(n);
        ll qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while(qh != qt) {
            ll v = q[qh++];
            id[v] = 2;
            if(qh == n) qh = 0;
            for(ll i=0; i<g[v].size(); ++i) {
                edge& r = e[g[v][i]];
                if(r.flow < r.cap && d[v] + r.cost < d[r.b]) {
                    d[r.b] = d[v] + r.cost;
                    if(id[r.b] == 0) {
                        q[qt++] = r.b;
                        if(qt == n) qt = 0;
                    }
                    else if(id[r.b] == 2) {
                        if(--qh == -1) qh = n-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_edge[r.b] = i;
                }
            }
        }
        if(d[t] == inf) break;
        ll addflow = inf;
        for(ll v=t; v!=s; v=p[v]) {
            ll pv = p[v]; ll pr = p_edge[v];
            addflow = min(addflow, e[g[pv][pr]].cap - e[g[pv][pr]].flow);
        }
        for(ll v=t; v!=s; v=p[v]) {
            ll pv = p[v]; ll pr = p_edge[v], r = e[g[pv][pr]].back;
            e[g[pv][pr]].flow += addflow;
            e[g[v][r]].flow -= addflow;
            cost += e[g[pv][pr]].cost * addflow;
        }
        flow += addflow;
    }
    return {flow,cost};
}

void reset() {
    e.clear();
    for(ll i = 0; i < n; i++) {
        g[i].clear();
    }
}

struct ed {
    ll s;
    ll t;
    ll c;
};

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> times;
    vector<ed> v;

    for(ll i = 0; i < n; i++) {
        ed t;
        cin >> t.s >> t.t >> t.c;
        t.t += t.s;
        times.push_back(t.s);
        times.push_back(t.t);
        v.push_back(t);
    }

    // Set up source
    times.push_back(-1);
    ::s = 0;


    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());

    // Set up sink
    ::t = times.size();
    ::n = ::t + 1;

    ::k = m;

    g.resize(MAXN);

    set<pair<int,int>> seen;

    // Add edges for the real edges
    for(auto i : v) {
        ll t1 = lower_bound(times.begin(),times.end(),i.s) - times.begin();
        ll t2 = lower_bound(times.begin(),times.end(),i.t) - times.begin();
        addedge(t1,t2,1,-i.c);
    }

    // Add edges for sequential times
    for(ll i = 0; i < ::n-1; i++) {
        addedge(i,i+1,m,0);
    }

    // Run maxflow
    pair<ll,ll> flow = getflow();

    // For each edge, print whether it's used
    for(ll i = 0; i < n*2; i+=2) {
        if(e[i].cap == e[i].flow) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    cout << endl;
}
