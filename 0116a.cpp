#include <bits/stdc++.h>

using namespace std;

int main() {
    int total = 0;
    int best = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        total += (b-a);
        best = max(best,total);
    }
    cout << best << endl;
}
