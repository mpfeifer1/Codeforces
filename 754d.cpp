#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;

struct operation {
    int val;
    int idx;
    bool op;

};

bool cmp(const operation lhs, const operation rhs) {
    if(lhs.val == rhs.val) {
        if(lhs.op == rhs.op) {
            return false;
        }
        return lhs.op;
    }
    return lhs.val < rhs.val;
}

operation ops[600004];
pair<ll,ll> v[300002];

bool calc(ll len, bool print = false) {
    len--;

    int spot = 0;
    for(ll i = 0; i < n; i++) {
        if(v[i].first <= v[i].second - len) {
            operation o1 = {v[i].first, i+1, true};
            operation o2 = {v[i].second - len, i+1, false};
            ops[spot]   = o1;
            ops[spot+1] = o2;
            spot+=2;
        }
    }

    if(spot == 0) {
        return false;
    }
    sort(ops, ops + spot, cmp);

    ll best = 0;
    int count = 0;
    for(int i = 0; i < spot; i++) {
        if(ops[i].op) {
            count++;
            best = max(best, (ll)count);
        }
        else {
            count--;
        }
    }

    return (best >= k);
}

void print(ll len) {
    len--;

    ll spot = 0;
    for(ll i = 0; i < n; i++) {
        if(v[i].first <= v[i].second - len) {
            ops[spot*2]   = {v[i].first, i+1, true};
            ops[spot*2+1] = {v[i].second - len, i+1, false};
            spot++;
        }
    }

    if(spot == 0) {
        return;
    }
    sort(ops, ops + spot*2, cmp);

    ll best = 0;
    set<ll> current;
    for(int i = 0; i < spot*2; i++) {
        if(ops[i].op) {
            current.insert(ops[i].idx);
            best = max(best, (ll)current.size());

            if(best == k) {
                for(auto j : current) {
                    cout << j << " ";
                }
                cout << endl;
                return;
            }
        }
        else {
            current.erase(ops[i].idx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // Scale input
    ll lowest = v[0].first;
    for(auto& i : v) {
        lowest = min(lowest, i.first);
        lowest = min(lowest, i.second);
    }
    for(auto& i : v) {
        i.first -= lowest;
        i.second -= lowest;
    }


    // Binary search for answer
    ll lo, mi, hi;
    lo = 0;
    hi = (ll)2000000010;

    ll best = 0;
    while(hi - lo > 1) {
        mi = (hi + lo) / 2;
        if(calc(mi)) {
            best = max(best, mi);
            lo = mi;
        }
        else {
            hi = mi;
        }
    }


    // Print answer
    if(best == 0) {
        cout << 0 << endl;
        for(ll i = 1; i <= k; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << best << endl;
        print(best);
    }

    return 0;
}
