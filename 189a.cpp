#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> v(n*2+2, -1);
    v[0] = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] > -1) {
            v[i+a] = max(v[i+a], v[i] + 1);
            v[i+b] = max(v[i+b], v[i] + 1);
            v[i+c] = max(v[i+c], v[i] + 1);
        }
    }

    cout << v[n] << endl;
}
