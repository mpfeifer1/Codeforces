#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int ones = 0;
    for(auto& i : v) {
        cin >> i;
        if(i == 1) {
            ones++;
        }
    }

    int best = -1;
    for(int i = 0; i < n; i++) {
        int increase = 0;
        for(int j = i; j < n; j++) {
            if(v[j] == 0) {
                increase++;
            }
            else {
                increase--;
            }
            best = max(increase, best);
        }
    }

    cout << ones + best << endl;
}
