#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& cycle, int parent, int curr) {
    bool incycle = false;

    for(auto i : adj[curr]) {
        if(i == parent) {
            continue;
        }

        if(visited[i]) {
            cycle[i] = true;
            incycle = true;
            break;
        }

        else {
            visited[i] = true;
            incycle |= dfs(adj, visited, cycle, curr, i);
        }
    }

    // If already part of a cycle, everything else won't be
    if(cycle[curr]) {
        incycle = false;
    }

    // If in a cycle, mark it
    if(incycle) {
        cycle[curr] = true;
    }

    // Return whether in a cycle
    return incycle;
}

int inf = 1 << 30;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<bool> cycle(n, false);
    vector<bool> visited(n, false);
    visited[0] = true;
    dfs(adj, visited, cycle, 0, 0);

    vector<int> dist(n,inf);

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(cycle[i]) {
            dist[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(dist[curr] + 1 < dist[i]) {
                dist[i] = dist[curr]+1;
                q.push(i);
            }
        }
    }

    for(auto i : dist) {
        cout << i << " ";
    }
    cout << endl;
}
