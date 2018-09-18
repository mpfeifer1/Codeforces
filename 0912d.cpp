#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll n, m, r, k;
vector<pair<ll,ll>> neigh = {{0,1}, {0,-1}, {1,0}, {-1,0}};

ll scoops(ll x, ll y) {
    return (min(n+1, x+r) - max(x,r)) * (min(m+1, y+r) - max(y,r));
}

bool inrange(ll x, ll y) {
    return (x > 0) && (y > 0) && (x <= n) && (y <= m);
}

int main() {
    cin >> n >> m >> r >> k;

    set<pair<ll,ll>> visited;
    priority_queue<pair<ll, pair<ll,ll>>> q;
    ll x = (n+1)/2;
    ll y = (m+1)/2;
    q.push({scoops(x, y), {x,y}});
    visited.insert({x,y});

    ll total = 0;
    while(!q.empty() && k--) {
        ll currx = q.top().second.first;
        ll curry = q.top().second.second;
        q.pop();

        total += scoops(currx,curry);

        for(auto i : neigh) {
            ll nextx = currx + i.first;
            ll nexty = curry + i.second;
            if(inrange(nextx, nexty) && visited.count({nextx,nexty}) == 0) {
                visited.insert({nextx, nexty});
                q.push({scoops(nextx, nexty), {nextx, nexty}});
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    ld ans = ((n-r+1) * (m-r+1));
    cout << (ld)total / ans << endl;
}
