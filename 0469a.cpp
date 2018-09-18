#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++) {
        v[i] = false;
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        v[t-1] = true;
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        v[t-1] = true;
    }

    bool works = true;
    for(int i = 0; i < n; i++) {
        works &= v[i];
    }

    if(works) {
        cout << "I become the guy." << endl;
    }
    else {
        cout << "Oh, my keyboard!" << endl;
    }
}
