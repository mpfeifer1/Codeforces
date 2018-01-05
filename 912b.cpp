#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pow2(ll n) {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return n;
}

int main() {
    ll n, k;
    cin >> n >> k;

    if(k == 1) {
        cout << n << endl;
    }
    else {
        cout << max(n, pow2(n)) << endl;
    }
}
