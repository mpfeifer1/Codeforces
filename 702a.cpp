#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto&i : v) {
        cin >> i;
    }

    int curr = v[0];
    int len = 1;
    int bestlen = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] > curr) {
            len++;
            bestlen = max(len, bestlen);
        }
        else {
            len = 1;
        }
        curr = v[i];
    }

    cout << bestlen << endl;
}
