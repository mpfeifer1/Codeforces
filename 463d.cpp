#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Build adjacency matrix
    vector<vector<int>> mat;
    mat.resize(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        vector<int> v(n);
        for(auto& i : v) {
            cin >> i;
            i--;
        }
        for(int j = 0; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                mat[v[j]][v[k]]++;
            }
        }
    }

    // Build adjacency list and degrees from matrix
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == m) {
                adj[i].push_back(j);
                deg[j]++;
            }
        }
    }

    // Find longest path
    vector<int> dist(n,1);

    queue<int> zeroin;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    int best = 1;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        for(auto i : adj[curr]) {
            deg[i]--;
            if(deg[i] == 0) {
                zeroin.push(i);
            }

            dist[i] = max(dist[i], dist[curr]+1);
            best = max(dist[i], best);
        }
    }

    cout << best << endl;
}
