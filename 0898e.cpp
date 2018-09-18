#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    set<ll> squares;
    for(ll i = 0; i < 500000; i++) {
        squares.insert(i*i);
    }

    ll n;
    cin >> n;

    vector<ll> g, b;

    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        if(temp == 0) {
            b.push_back(2);
        }
        // If square, dist = 1
        else if(squares.count(temp) > 0) {
            b.push_back(1);
        }
        else {
            ll newnum = round(sqrt(temp));
            newnum *= newnum;
            ll dist = abs(temp - newnum);
            g.push_back(dist);
        }

    }

    sort(b.rbegin(), b.rend());
    sort(g.rbegin(), g.rend());

    ll total = 0;

    while(g.size() < b.size()) {
        total += b.back();
        b.pop_back();
        g.push_back(1);
    }
    while(b.size() < g.size()) {
        total += g.back();
        g.pop_back();
        b.push_back(1);
    }

    cout << total << endl;
}
