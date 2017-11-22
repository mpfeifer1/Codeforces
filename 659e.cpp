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
    int n, m;
    cin >> n >> m;

    vector<int> disjoint(n, -1);
    vector<bool> cycle(n, false);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        if(find(disjoint, n1) == find(disjoint, n2)) {
            cycle[n1] = true;
            cycle[n2] = true;
        }

        join(disjoint, n1, n2);
    }

    unordered_map<int, pair<int, bool>> s;
    for(int i = 0; i < n; i++) {
        int par = find(disjoint, i);
        if(s.count(par) == 0) {
            s[par] = {0, false};
        }

        s[par].first++;
        if(cycle[i]) {
            s[par].second = true;
        }
    }

    int total = 0;
    for(auto i : s) {
        if(!i.second.second) {
            total++;
            continue;
        }
        if(i.second.first == 1) {
            total++;
            continue;
        }
    }

    cout << total << endl;
}
