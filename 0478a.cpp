#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    for(int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        n += temp;
    }

    if(n % 5 == 0 && n > 0) {
        cout << n/5 << endl;
    }
    else {
        cout << -1 << endl;
    }
}
