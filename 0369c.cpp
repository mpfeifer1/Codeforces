#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    vector<int> b;
    vector<int> g;
    bool visited;
    bool elect;
};

bool dfs(vector<node>& v, int curr, bool needcover) {
    bool covered = !needcover;
    v[curr].visited = true;

    bool someoneelected = false;

    for(auto i : v[curr].g) {
        if(!v[i].visited) {
            someoneelected |= dfs(v, i, false);
            covered &= someoneelected;
        }
    }
    for(auto i : v[curr].b) {
        if(!v[i].visited) {
            someoneelected |= dfs(v, i, true);
            covered &= someoneelected;
        }
    }

    if(someoneelected) {
        covered = true;
    }

    if(needcover && !covered) {
        v[curr].elect = true;
        covered = true;
        someoneelected = true;
    }

    return someoneelected;
}

int main() {
    int n;
    cin >> n;

    node empty;
    empty.visited = false;
    empty.elect = false;
    vector<node> v(n, empty);

    for(int i = 0; i < n-1; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        n1--;
        n2--;

        if(w == 1) {
            v[n1].g.push_back(n2);
            v[n2].g.push_back(n1);
        }
        else {
            v[n1].b.push_back(n2);
            v[n2].b.push_back(n1);
        }
    }

    // Run a DFS to find placings
    dfs(v, 0, false);

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(v[i].elect) {
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
