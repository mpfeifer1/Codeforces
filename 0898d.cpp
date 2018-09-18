#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> ring(1000005, false);

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ring[temp-1] = true;
    }

    int turnoff = 0;

    int count = 0;
    for(int i = 0; i < m; i++) {
        if(ring[i]) {
            count++;
        }
    }

    for(int i = m-1; i >= 0; i--) {
        if(ring[i] && count >= k) {
            count--;
            turnoff++;
            ring[i] = false;
        }
    }

    for(int i = m; i < 1000005; i++) {
        if(ring[i]) {
            count++;
        }
        if(ring[i-m]) {
            count--;
        }

        if(count >= k) {
            turnoff++;
            count--;
            ring[i] = false;
        }
    }

    cout << turnoff << endl;
}
