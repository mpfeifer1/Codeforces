#include <bits/stdc++.h>

using namespace std;

struct edge {
    int op;
    int n1, n2;
};

int find(vector<int>&d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    // Read in input
    vector<int> d(n);
    vector<vector<pair<int, int>>> adj(n);
    unordered_map<string, int> stringtoint;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        stringtoint[s] = i;

        d[i] = -1;
        adj[i] = {};
    }

    // Build Tree
    vector<edge> edges(m);
    for(auto& e : edges) {
        string t1, t2;
        cin >> e.op >> t1 >> t2;
        e.n1 = stringtoint[t1];
        e.n2 = stringtoint[t2];
        if(find(d, e.n1) != find(d, e.n2)) {
            join(d, e.n1, e.n2);
            adj[e.n1].push_back({e.n2, e.op});
            adj[e.n2].push_back({e.n1, e.op});
        }
    }

    // Search to find "colors"
    vector<int> color(n, -1);
    queue<int> qu;
    for(int j = 0; j < n; j++) {
        if(color[j] == -1) {
            color[j] = 0;
            qu.push(j);
        }
        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for(auto i : adj[curr]) {
                if(color[i.first] == -1) {
                    if(i.second == 1) {
                        color[i.first] = color[curr];
                    }
                    else {
                        color[i.first] = (color[curr] + 1) % 2;
                    }
                    qu.push(i.first);
                }
            }
        }
    }

    // Run Tree Queries
    for(auto i : edges) {
        bool same = color[i.n1] == color[i.n2];
        if((same && i.op == 1) || (!same && i.op == 2)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    // Run Word Queries
    for(int i = 0; i < q; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int t1 = stringtoint[s1];
        int t2 = stringtoint[s2];

        if(find(d, t1) != find(d, t2)) {
            cout << "3" << endl;
        }
        else {
            if(color[t1] == color[t2]) {
                cout << "1" << endl;
            }
            else {
                cout << "2" << endl;
            }
        }
    }
}
