#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct color{
    ll t;
    char c;
};

ll solve2(vector<color>& v) {
    ll greens = 0;
    for(auto i : v) {
        if(i.c == 'G') {
            greens++;
        }
    }

    // Split into R and B
    vector<color> r;
    vector<color> b;
    for(auto i : v) {
        if(i.c == 'G') {
            r.push_back(i);
            b.push_back(i);
        }
        if(i.c == 'R') {
            r.push_back(i);
        }
        if(i.c == 'B') {
            b.push_back(i);
        }
    }

    if(greens == 0 || greens == 1) {
        ll total = 0;
        for(ll i = 1; i < r.size(); i++) {
            total += r[i].t - r[i-1].t;
        }
        for(ll i = 1; i < b.size(); i++) {
            total += b[i].t - b[i-1].t;
        }
        return total;
    }
    if(greens == 2) {
        ll greendiff = v.back().t - v.front().t;

        ll rtotal = 0;
        ll rbest = 0;
        for(ll i = 1; i < r.size(); i++) {
            rtotal += r[i].t - r[i-1].t;
            rbest = max(rbest, r[i].t - r[i-1].t);
        }

        ll btotal = 0;
        ll bbest = 0;
        for(ll i = 1; i < b.size(); i++) {
            btotal += b[i].t - b[i-1].t;
            bbest = max(bbest, b[i].t - b[i-1].t);
        }

        ll total = min(greendiff + rtotal + btotal - rbest - bbest, rtotal + btotal);

        return total;
    }
}

ll solve(vector<color>& v) {
    vector<vector<color>> o;
    o.push_back({});

    // Split by G
    for(ll i = 0; i < v.size(); i++) {
        if(v[i].c == 'G') {
            o.back().push_back(v[i]);
            o.push_back({});
            o.back().push_back(v[i]);
        }
        else {
            o.back().push_back(v[i]);
        }
    }

    ll total = 0;
    for(auto i : o) {
        total += solve2(i);
    }

    return total;
}

int main() {
    ll n;
    cin >> n;

    vector<color> v;

    for(ll i = 0; i < n; i++) {
        color c;
        cin >> c.t >> c.c;

        v.push_back(c);
    }

    cout << solve(v) << endl;
}
