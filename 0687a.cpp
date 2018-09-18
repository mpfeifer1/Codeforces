#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<bool, bool>> v(n+1, {false, false});
    vector<vector<int>> adj(n+1);
    vector<int> v1, v2;

    // Grab all edges
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    // Divide up each cycle
    for(int i = 1; i < v.size(); i++) {
        if(!v[i].first) {
            queue<int> q;
            q.push(i);
            v[i].first = true;
            v[i].second = true;
            while(!q.empty()) {
                int curr = q.front();
                bool person = v[curr].second;
                q.pop();

                if(person) {
                    v1.push_back(curr);
                }
                else {
                    v2.push_back(curr);
                }

                for(auto j : adj[curr]) {
                    if(!v[j].first) {
                        v[j].first = true;
                        v[j].second = !person;
                        q.push(j);
                    }
                    else {
                        if(v[j].second == v[curr].second) {
                            cout << "-1" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << v1.size() << endl;
    for(auto i : v1) {
        cout << i << " ";
    }
    cout << endl;

    cout << v2.size() << endl;
    for(auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
}
