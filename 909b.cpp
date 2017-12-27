#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total = n * (n+1) / 2;

    vector<int> memo(n,0);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = j; k < i; k++) {
                memo[k]++;
            }
        }
    }

    int best = 0;
    for(int i = 0; i < n; i++) {
        best = max(best, memo[i]);
    }

    cout << best << endl;
}
