#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r1, r2;
    cin >> n >> r1 >> r2;

    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++) {
        if(i == r1) {
            continue;
        }

        int num;
        cin >> num;

        adj[num].push_back(i);
        adj[i].push_back(num);
    }

    vector<int> vis(n+1, -1);
    queue<int> q;
    vis[r2] = 0;
    q.push(r2);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(vis[i] == -1) {
                vis[i] = curr;
                q.push(i);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == r2) {
            continue;
        }
        cout << vis[i] << " ";
    }
    cout << endl;
}
