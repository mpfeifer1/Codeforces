#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> color(n);
    vector<int> d(n, -1);
    vector<pair<int,int>> input;

    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        input.push_back({n1, n2});
    }

    for(auto& i : color) {
        cin >> i;
    }

    for(auto i : input) {
        if(color[i.first] == color[i.second]) {
            join(d, i.first, i.second);
        }
    }

    int groups = 0;
    for(auto i : d) {
        if(i == -1) {
            groups++;
        }
    }

    for(int i = 0; i < n; i++) {
        unordered_set<int> colorshere;
        colorshere.insert(find(d, i));

        for(auto j : adj[i]) {
            colorshere.insert(find(d, j));
        }

        if(colorshere.size() == groups) {
            cout << "YES" << endl << i+1 << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
