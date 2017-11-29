#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll inf = ((ll)1 << 63) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Set up input
    ll n, m, k;
    cin >> n >> m >> k;

    // Read in roads
    vector<vector<pair<ll,int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        adj[n1].push_back({w, n2});
        adj[n2].push_back({w, n1});
    }

    // Read in tracks
    priority_queue<pair<ll,int>> q;
    for(int i = 0; i < k; i++) {
        int n1, w;
        cin >> n1 >> w;
        q.push({-w, -n1});
    }
    q.push({0,1});
    int count = 0;

    // Set up visited
    vector<bool> visited(n+2, false);

    // Run Dijkstra's
    while(!q.empty()) {
        pair<ll,int> curr = q.top();
        q.pop();

        ll d = -curr.first;
        int u = curr.second;
        if(u < 0 && visited[u = -u]) {
            count++;
        }

        if(visited[u]) {
            continue;
        }
        visited[u] = true;

        for(auto next : adj[u]) {
            if(!visited[next.second]) {
                q.push({-(d + next.first), next.second});
            }
        }
    }

    // Print answer
    cout << count << endl;
}
