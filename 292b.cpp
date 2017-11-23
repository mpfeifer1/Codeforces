#include <bits/stdc++.h>

using namespace std;

bool isbus(vector<int>& deg) {
    int n = 0;

    for(auto i : deg) {
        if(i > 2) {
            return false;
        }
        if(i == 1) {
            n++;
        }
    }

    return (n == 2);
}

bool isring(vector<int>& deg) {
    for(auto i : deg) {
        if(i != 2) {
            return false;
        }
    }

    return true;
}
bool isstar(vector<pair<int, int>>& in, int n) {
    vector<int> count(n, 0);
    for(auto i : in) {
        count[i.first]++;
        count[i.second]++;
    }

    int notone = 0;
    for(auto i : count) {
        if(i != 1) {
            notone++;
        }
    }

    return (notone == 1);
}

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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    vector<int> disjoint(n, -1);
    vector<pair<int, int>> input;

    // Build graph
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        input.push_back({n1,n2});

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);

        deg[n1]++;
        deg[n2]++;

        join(disjoint, n1, n2);
    }

    // Check it's completely connected
    int par = find(disjoint, 0);
    for(int i = 1; i < n; i++) {
        if(find(disjoint, i) != par) {
            cout << "unknown topology" << endl;
            return 0;
        }
    }

    // Find correct type
    if(isbus(deg)) {
         cout << "bus topology" << endl;
    }
    else if(isring(deg)) {
         cout << "ring topology" << endl;
    }
    else if(isstar(input, n)) {
         cout << "star topology" << endl;
    }
    else {
         cout << "unknown topology" << endl;
    }
}
