#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<pair<int,bool>>>& adj, vector<int>& color, int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        int col = color[curr];

        for(auto i : adj[curr]) {
            int next = i.first;
            bool same = i.second;
            int nextcol = color[next];

            if(nextcol == -1) {
                if(same) {
                    color[next] = col;
                }
                else {
                    color[next] = col ^ 1;
                }
                q.push(next);
            }

            else {
                if(same && col != nextcol) {
                    return false;
                }
                if(!same && col == nextcol) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Take in doors
    vector<int> locked(n);
    for(auto& i : locked) {
        cin >> i;
    }

    // Take in switches
    vector<pair<int,int>> doors(n, {-1,-1});
    for(int i = 0; i < m; i++) {
        int count;
        cin >> count;

        for(int j = 0; j < count; j++) {
            int dest;
            cin >> dest;
            dest--;

            if(doors[dest].first == -1) {
                doors[dest].first = i;
            }
            else {
                doors[dest].second = i;
            }
        }
    }

    // Build adjacency list
    vector<vector<pair<int,bool>>> adj(m);
    for(int i = 0; i < n; i++) {
        int n1 = doors[i].first;
        int n2 = doors[i].second;
        bool same = (locked[i] == 1);

        adj[n1].push_back({n2,same});
        adj[n2].push_back({n1,same});
    }

    // Find color matching
    vector<int> color(m, -1);
    bool works = true;
    for(int i = 0; i < m; i++) {
        if(color[i] == -1) {
            color[i] = 0;
            works &= bfs(adj, color, i);
        }
    }

    // Print answer
    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
