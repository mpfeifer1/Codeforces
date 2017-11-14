#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct edge {
    ll n1, n2, w;
};

int main() {
    int n, e, s;
    cin >> n >> e >> s;

    vector<edge> v;
    for(int i = 0; i < e; i++) {
        edge e1;
        cin >> e1.n1 >> e1.n2 >> e1.w;
        v.push_back(e1);
    }

    unordered_set<ll> seen;
    for(int i = 0; i < s; i++) {
        ll temp;
        cin >> temp;
        seen.insert(temp);
    }

    ll best = (ll)1 << 50;
    for(auto i : v) {
        if((seen.count(i.n1) > 0) ^ (seen.count(i.n2) > 0)) {
            best = min(best, i.w);
        }
    }

    if(best == (ll)1 << 50) {
        cout << "-1" << endl;
    }
    else {
        cout << best << endl;
    }
}
