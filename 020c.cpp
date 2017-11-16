#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
ll inf = (ll) 1 << 50;

struct node {
    ll dist;
    ll parent;
    vector<pair<ll, ll>> neighbors;
};

int main() {
    ll v, e;
    cin >> v >> e;

    node empty;
    empty.dist = inf;
    empty.parent = -1;
    vector<node> nodes(v, empty);

    for(ll i = 0; i < e; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;
        n1--;
        n2--;

        nodes[n1].neighbors.push_back({n2,w});
        nodes[n2].neighbors.push_back({n1,w});
    }

    nodes[0].dist = 0;
    priority_queue<pair<ll,ll>> q;
    q.push({0,0});

    while(!q.empty()) {
        ll curr = q.top().second;
        q.pop();

        for(auto i : nodes[curr].neighbors) {
            ll next = i.first;
            ll weight = i.second;
            ll dist1 = nodes[curr].dist + weight;
            ll dist2 = nodes[next].dist;
            if(dist1 < dist2) {
                nodes[next].parent = curr;
                nodes[next].dist = dist1;
                q.push({weight, next});
            }
        }
    }

    if(nodes[v-1].dist > inf / 2) {
        cout << "-1" << endl;
    }
    else {
        // Build list
        vector<ll> print;
        ll curr = v-1;
        while(curr != -1) {
            print.push_back(curr);
            curr = nodes[curr].parent;
        }

        // Print list
        for(int i = print.size()-1; i >= 0; i--) {
            cout << print[i] + 1 << " ";
        }
        cout << endl;
    }
}
