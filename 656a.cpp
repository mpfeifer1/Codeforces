#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll ans = 1;
    for(int i = 0; i < n; i++) {
        ans *= 2;
        if(i == 12) {
            ans -= 100;
        }
    }
    cout << ans << endl;
}
