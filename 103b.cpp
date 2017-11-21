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

    vector<int> connected(n, -1);
    bool cycle = false;

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        if(find(connected, n1) == find(connected, n2)) {
            if(cycle) {
                cout << "NO" << endl;
                return 0;
            }
            cycle = true;
        }
        join(connected, n1, n2);

    }

    // Check graph is completely connected
    int parent = find(connected, 0);
    for(int i = 1; i < n; i++) {
        if(find(connected, i) != parent) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if(cycle) {
        cout << "FHTAGN!" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}
