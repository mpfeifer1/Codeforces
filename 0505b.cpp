#include <iostream>
#include <vector>

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

    vector<vector<int>> v;
    v.resize(m, vector<int>(n, -1));

    for(int i = 0; i < m; i++) {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;
        n1--;
        n2--;
        c--;

        join(v[c], n1, n2);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int q1, q2;
        cin >> q1 >> q2;
        q1--;
        q2--;

        int total = 0;
        for(int j = 0; j < m; j++) {
            if(find(v[j], q1) == find(v[j], q2)) {
                total++;
            }
        }

        cout << total << endl;
    }
}
