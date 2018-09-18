// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





int main() {
    //file();
    //fast();

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    vector<set<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }

    vector<int> dists(n, iinf);
    vector<int> distt(n, iinf);

    queue<int> q;

    q.push(s);
    dists[s] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dists[next] == iinf) {
                dists[next] = dists[curr]+1;
                q.push(next);
            }
        }
    }

    q.push(t);
    distt[t] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(distt[next] == iinf) {
                distt[next] = distt[curr]+1;
                q.push(next);
            }
        }
    }

    int maxdist = distt[s];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(adj[i].count(j) > 0) {
                continue;
            }

            if(distt[i] + dists[j] + 1 < maxdist || dists[i] + distt[j] + 1 < maxdist) {
                continue;
            }

            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
