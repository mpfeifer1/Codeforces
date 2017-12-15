#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<int,int>& adj, vector<int>& v, int start) {
    while(adj.count(start) != 0) {
        v.push_back(start);
        start = adj[start];
        if(start == 0) {
            break;
        }
    }
    v.push_back(start);
}

int main() {
    int n;
    cin >> n;

    unordered_map<int,int> adj;
    unordered_map<int,int> deg;

    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if(n2 == 0) {
            if(deg.count(n1) == 0) {
                deg[n1] = 0;
            }
            continue;
        }

        adj[n1] = n2;

        deg[n2]++;
        if(deg.count(n1) == 0) {
            deg[n1] = 0;
        }
    }

    vector<int> v1;
    vector<int> v2;

    vector<int> zeroin;
    for(auto i : deg) {
        if(i.second == 0) {
            zeroin.push_back(i.first);
        }
    }

    dfs(adj, v1, zeroin[0]);
    dfs(adj, v2, zeroin[1]);

    if(v2[0] == 0) {
        swap(v1, v2);
    }

    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != 0) {
            cout << v1[i] << " ";
        }
        if(i < v2.size() && v2[i] != 0) {
            cout << v2[i] << " ";
        }
    }
    cout << endl;
}
