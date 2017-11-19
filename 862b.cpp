#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct node {
    bool visited;
    bool color;
    vector<ll> neighbors;
};

int main() {
    ll n;
    cin >> n;

    node empty;
    empty.visited = false;
    empty.color = false;
    vector<node> v(n, empty);

    for(ll i = 0; i < n-1; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        v[n1].neighbors.push_back(n2);
        v[n2].neighbors.push_back(n1);
    }

    queue<ll> q;
    q.push(0);
    v[0].visited = true;

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        for(auto i : v[curr].neighbors) {
            if(!v[i].visited) {
                v[i].visited = true;
                v[i].color = !v[curr].color;
                q.push(i);
            }
        }

    }

    ll c1 = 0, c2 = 0;
    for(ll i = 0; i < n; i++) {
        if(v[i].color) {
            c1++;
        }
        else {
            c2++;
        }
    }

    cout << (c1 * c2) - (n-1) << endl;
}
