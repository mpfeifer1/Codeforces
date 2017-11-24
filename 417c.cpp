#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if(n < 2 * m + 1) {
        cout << "-1" << endl;
        return 0;
    }

    cout << n * m << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int n1 = i+1;
            int n2 = (i+j+1) % n + 1;

            cout << n1 << " " << n2 << "\n";
        }
    }
}
