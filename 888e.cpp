#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    unordered_set<ll> a;
    for(ll k = 0; k < v.size()/2; k++) {
        ll num = v[k];
        unordered_set<ll> b;
        b.insert(num % m);
        for(auto i : a) {
            b.insert((i + num) % m);
        }
        for(auto i : b) {
            a.insert(i);
        }
    }

    unordered_set<ll> c;
    for(ll k = v.size()/2; k < v.size(); k++) {
        ll num = v[k];
        unordered_set<ll> d;
        d.insert(num % m);
        for(auto i : c) {
            d.insert((i + num) % m);
        }
        for(auto i : d) {
            c.insert(i);
        }
    }

    vector<int> lo;
    vector<int> hi;

    for(auto i : a) {
        lo.push_back(i);
    }
    for(auto i : c) {
        hi.push_back(i);
    }

    sort(lo.begin(), lo.end());
    sort(hi.begin(), hi.end());

    ll best = 0;
    if(lo.size() > 0) {
        ll temp = lo.back();
        best = max(best, temp);
    }
    if(hi.size() > 0) {
        ll temp = hi.back();
        best = max(best, temp);
    }

    ll idx1 = 0, idx2 = hi.size()-1;
    while(idx1 < lo.size() && idx2 >= 0) {
        ll actual, temp;
        actual = (lo[idx1] + hi[idx2]);
        temp = actual % m;
        best = max(best, temp);

        if(actual > temp) {
            idx2--;
        }
        else {
            idx1++;
        }
    }

    cout << best << endl;
}
