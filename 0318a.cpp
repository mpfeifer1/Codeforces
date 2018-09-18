#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    if(b <= (a+1) / 2) {
        cout << 2 * b - 1 << endl;
    }
    else {
        cout << (b - (a+1) / 2) * 2 << endl;
    }
}
