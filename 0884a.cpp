#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int i;
    for(i = 0; i < n; i++) {
        int a;
        cin >> a;

        t -= (86400 - a);

        if(t <= 0) {
            break;
        }
    }

    cout << i+1 << endl;
}
