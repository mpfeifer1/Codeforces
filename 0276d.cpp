#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << endl;
        return 0;
    }

    ll mask = (ll) 1 << 60;

    while(mask > 0) {
        if(((a^b) & mask) != 0) {
            cout << (mask << 1) - 1 << endl;
            return 0;
        }

        mask >>= 1;
    }
}
