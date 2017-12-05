#include <bits/stdc++.h>

using namespace std;
const int inf = 1 << 30;

int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for(int i = 0; i < p; i++) {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;

        n1--;
        n2--;

        indegree[n2]++;
        outdegree[n1]++;

        adj[n1].push_back({n2, c});
    }

    // Find all paths
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0 && outdegree[i] > 0) {
            count++;
        }
    }
    cout << count << endl;

    // Print all paths
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0 && outdegree[i] > 0) {
            cout << i+1 << " ";
            int curr = i;
            int maxcap = inf;
            while(adj[curr].size() > 0) {
                maxcap = min(maxcap, adj[curr][0].second);
                curr = adj[curr][0].first;
            }
            cout << curr+1 << " " << maxcap << endl;
        }
    }
}
