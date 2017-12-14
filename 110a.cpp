#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll count = 0;
    while(n > 0) {
        if(n % 10 == 7 || n % 10 == 4) {
            count++;
        }
        n /= 10;
    }

    if(count == 4 || count == 7) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
