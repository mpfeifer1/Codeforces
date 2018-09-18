#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a;
    cin >> a;

    if(a % 2 == 1 || a < 4) {
        cout << 0 << endl;
        return 0;
    }

    a /= 2;

    if(a % 2 == 0) {
        a /= 2;
        a--;
    }
    else {
        a /= 2;
    }

    cout << a << endl;
}
