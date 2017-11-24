#include <bits/stdc++.h>

using namespace std;

bool iscomp(int n) {
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for(int i = n/2; i >= 2; i--) {
        if(iscomp(i) && iscomp(n-i)) {
            cout << i << " " << n-i << endl;
            return 0;
        }
    }
}
