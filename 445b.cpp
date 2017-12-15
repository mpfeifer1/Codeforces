#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

    vector<int> d(n, -1);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        join(d, n1, n2);
    }

    unordered_map<int,int> count;
    for(int i = 0; i < n; i++) {
        count[find(d,i)]++;
    }

    ll total = 0;
    for(auto i : count) {
        total += i.second - 1;
    }

    cout << (ll)pow((ll)2, total) << endl;
}
