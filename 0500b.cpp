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

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<int> d(n, -1);

    // Join connected components
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if(c == '1') {
                join(d, i, j);
            }
        }
    }

    // Split compontnts by their parent
    unordered_map<int, vector<int>> m;
    for(int i = 0; i < n; i++) {
        int par = find(d, i);
        m[par].push_back(v[i]);
    }

    // Sort each component
    for(auto& i : m) {
        sort(i.second.rbegin(), i.second.rend());
    }

    // Print component elements as we need them
    for(int i = 0; i < n; i++) {
        int par = find(d, i);
        cout << m[par].back() << " ";
        m[par].pop_back();
    }
    cout << endl;
}
