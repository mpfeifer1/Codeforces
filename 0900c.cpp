#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)10000000;

int main() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<bool> good(n, false);

    ll best = 0;
    for(ll i = 0; i < v.size(); i++) {
        if(v[i] > best) {
            best = v[i];
            good[i] = true;
        }
    }

    vector<pair<ll,ll>> cand;
    ll currmin = 0;
    for(ll i = 0; i < good.size()-1; i++) {
        if(good[i] && !good[i+1]) {
            cand.push_back({i,currmin});
        }
        currmin = max(v[i], currmin);
    }

    ll bestcand = inf;
    ll bestval = 0;
    currmin = 0;
    for(auto i : cand) {
        currmin = i.second;
        ll currval = 0;
        for(ll j = i.first+1; !good[j] && j < v.size(); j++) {
            if(v[j] > currmin) {
                currval++;
                currmin = max(currmin, v[j]);
                if(currval > bestval) {
                    bestval = currval;
                    bestcand = v[i.first];
                }
                if(currval == bestval) {
                    bestcand = min(v[i.first], bestcand);
                }
            }
        }
    }

    if(bestval <= 1) {
        ll best = inf;
        for(ll i = 0; i < n; i++) {
            if(!good[i]) {
                best = min(v[i], best);
            }
        }

        if(best == inf) {
            cout << "1" << endl;
        }
        else {
            cout << best << endl;
        }
    }
    else {
        cout << bestcand << endl;
    }
}
