#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inf = 2 << 28;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> visited(n, inf);

    vector<vector<bool>> adj;
    adj.resize(n, vector<bool>(n, false));

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    // If we can get there directly, the other side gets to use it
    if(adj[0][n-1]) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = !adj[i][j];
            }
        }
    }

    // Run a BFS to see how fast we can get there
    queue<int> q;
    q.push(0);
    visited[0] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            if(adj[curr][i]) {
                if(visited[curr] + 1 < visited[i]) {
                    visited[i] = visited[curr]+1;
                    q.push(i);
                }
            }
        }
    }

    if(visited[n-1] == inf) {
        cout << "-1" << endl;
        return 0;
    }
    cout << visited[n-1] << endl;
}
