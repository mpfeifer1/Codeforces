#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    while(n % 10 != 0) {
        if(n % 10 < 5) {
            n--;
        }
        else {
            n++;
        }
    }

    cout << n << endl;
}
