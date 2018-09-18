#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        x -= temp+1;
    }

    if(x == -1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
