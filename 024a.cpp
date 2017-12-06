#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<pair<int,int>, int> cost;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;
        n1--;
        n2--;

        cost[{n1,n2}] = c;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<bool> visited(n, false);
    vector<int> order;
    int curr = 0;

    // Build order
    while(!visited[curr]) {
        visited[curr] = true;
        order.push_back(curr);

        int next;
        if(visited[adj[curr][0]]) {
            next = adj[curr][1];
        }
        else {
            next = adj[curr][0];
        }

        curr = next;
    }

    // Find best price
    order.push_back(0);
    int c1 = 0, c2 = 0;
    for(int i = 0; i < order.size()-1; i++) {
        c1 += cost[{order[i],order[i+1]}];
        c2 += cost[{order[i+1],order[i]}];
    }

    cout << min(c1, c2) << endl;
}
