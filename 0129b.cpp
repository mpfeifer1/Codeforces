#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n, 0);
    vector<vector<int>> adj;
    adj.resize(n);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        deg[n1]++;
        deg[n2]++;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    int total = 0;
    queue<int> zero;

    do {
        // Remove leaf nodes
        while(!zero.empty()) {
            int i = zero.front();
            zero.pop();

            deg[i]--;
            for(auto j : adj[i]) {
                deg[j]--;
            }
        }

        // Find new leaf nodes
        for(int i = 0; i < n; i++) {
            if(deg[i] == 1) {
                zero.push(i);
            }
        }

        // If there are more to kick out, add 1 to count
        if(zero.size() > 0) {
            total++;
        }

    } while(zero.size() != 0);

    cout << total << endl;
}
