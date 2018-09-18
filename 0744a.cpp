#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> degrees(n, 0);
    vector<ll> disjoint(n, -1);

    vector<ll> govs(k);

    for(auto& i : govs) {
        cin >> i;
        i--;
    }

    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        degrees[n1]++;
        join(disjoint, n1, n2);
    }

    ll extranodes = 0;
    ll extraedges = 0;

    map<ll, pair<ll,ll>> clusters;
    for(auto i : govs) {
        clusters[find(disjoint, i)] = {0,0};
    }

    for(ll i = 0; i < n; i++) {
        ll spot = find(disjoint, i);
        if(clusters.count(spot)) {
            pair<ll, ll> curr = clusters[spot];
            curr.first++;
            curr.second += degrees[i];
            clusters[spot] = curr;
        }
        else {
            extranodes++;
            extraedges += degrees[i];
        }
    }

    vector<pair<ll,ll>> v;
    for(auto i : clusters) {
        v.push_back(i.second);
    }
    sort(v.rbegin(), v.rend());
    v[0].first += extranodes;
    v[0].second += extraedges;

    ll total = 0;
    for(auto i : v) {
        total += (i.first * (i.first - 1) / 2) - i.second;
    }

    cout << total << endl;
}
