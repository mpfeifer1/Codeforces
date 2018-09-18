#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>>& adj, int start, int end) {
    vector<bool> v(adj.size(), false);

    queue<int> q;
    q.push(start);
    v[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            if(!v[i]) {
                v[i] = true;
                q.push(i);
            }
        }
    }

    return v[end];
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    vector<vector<int>> adj;

    for(int i = 0; i < n; i++) {
        int q, n1, n2;
        cin >> q >> n1 >> n2;

        if(q == 1) {
            adj.push_back({});

            for(int j = 0; j < v.size(); j++) {
                if(v[j].first < n1 && n1 < v[j].second) {
                    adj[v.size()].push_back(j);
                }
                else if(v[j].first < n2 && n2 < v[j].second) {
                    adj[v.size()].push_back(j);
                }

                if(n1 < v[j].first && v[j].first < n2) {
                    adj[j].push_back(v.size());
                }
                else if(n1 < v[j].second && v[j].second < n2) {
                    adj[j].push_back(v.size());
                }
            }

            v.push_back({n1,n2});
        }
        else {
            n1--;
            n2--;

            // DFS from n1 to n2
            if(bfs(adj, n1, n2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
