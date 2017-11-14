#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll a;
    cin >> a;

    int total = 0;
    while(a > 0) {
        if(a % 2 == 1) {
            total++;
        }
        a >>= 1;
    }

    cout << total << endl;
}
