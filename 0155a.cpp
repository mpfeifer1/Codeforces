#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int lo = v[0];
    int hi = v[0];

    int amaz = 0;

    for(int i = 1; i < n; i++) {
        if(v[i] < lo) {
            amaz++;
            lo = v[i];
        }
        if(v[i] > hi) {
            amaz++;
            hi = v[i];
        }
    }

    cout << amaz << endl;
}
