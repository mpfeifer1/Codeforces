#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//ll inf = (ll) 1 << 60;
int inf = 1<<30;

int main() {
    int n, m, maxlen;
    cin >> n >> m >> maxlen;

    // Adjacency list of neighbor, weight
    vector<vector<pair<int,int>>> adj(n);

    // Read in input
    for(int i = 0; i < m; i++) {
        int n1, n2, t;
        cin >> n1 >> n2 >> t;

        n1--;
        n2--;

        if(n2 != 0) {
            adj[n1].push_back({n2,t});
        }
    }

    // DP array with min dist to get here in N steps, parent
    vector<vector<pair<int,int>>> dp;
    dp.resize(n, vector<pair<int,int>>(m+1, {inf, -1}));

    // Count all nodes degrees
    vector<int> deg(n, 0);
    for(auto i : adj) {
        for(auto j : i) {
            deg[j.first]++;
        }
    }

    // Find all extras with degree 0
    queue<int> extrazero;
    for(int i = 1; i < n; i++) {
        if(deg[i] == 0) {
            extrazero.push(i);
        }
    }

    // Remove all extras with degree 0
    while(!extrazero.empty()) {
        int curr = extrazero.front();
        extrazero.pop();

        for(auto i : adj[curr]) {
            int next = i.first;
            deg[next]--;

            if(deg[next] == 0) {
                extrazero.push(next);
            }
        }
    }

    // Queue of node to check, weight to get there
    queue<int> zeroin;
    zeroin.push(0);
    dp[0][0] = {0,-1};

    // Toposort, filling in memo table
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        for(auto i : adj[curr]) {
            int next = i.first;
            int w = i.second;

            deg[next]--;
            if(deg[next] == 0) {
                zeroin.push(next);
            }

            for(int j = 0; j < m; j++) {
                if(dp[curr][j].first + w < dp[next][j+1].first) {
                    dp[next][j+1] = {dp[curr][j].first + w, curr};
                }
            }
        }
    }

    // Find end node
    int steps = 1000000;
    int node  = 1000000;
    for(int i = m; i >= 0; i--) {
        if(dp[n-1][i].first <= maxlen) {
            steps = i;
            node = n-1;
            break;
        }
    }

    // Build path
    vector<int> ans;
    while(node != -1) {
        ans.push_back(node+1);
        node = dp[node][steps].second;
        steps--;
    }

    // Print path
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
