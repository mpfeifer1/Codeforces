#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int total = 1;
    for(int i = 1; i < n; i++) {
        if(v[i-1] != v[i]) {
            total++;
        }
    }

    cout << total << endl;
}
