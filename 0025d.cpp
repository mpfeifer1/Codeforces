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

    vector<int> d(n+1, -1);

    vector<pair<int, int>> extra;
    vector<pair<int, int>> need;

    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if(find(d, n1) == find(d, n2)) {
            extra.push_back({n1, n2});
        }
        join(d, n1, n2);
    }

    for(int i = 2; i <= n; i++) {
        if(find(d, i) != find(d, 1)) {
            need.push_back({1, i});
            join(d, 1, i);
        }
    }

    cout << extra.size() << endl;
    for(int i = 0; i < extra.size(); i++) {
        cout << extra[i].first << " " << extra[i].second << " ";
        cout << need[i].first << " " << need[i].second << endl;
    }
}
