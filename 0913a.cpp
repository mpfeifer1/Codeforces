#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    ll mod = 1;
    int k = 0;

    while(k < n) {
        if(mod > m) {
            break;
        }
        mod *= 2;
        k++;
    }

    cout << m % mod << endl;
}
