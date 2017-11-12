#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll total = ceil(double(a) / c) * ceil(double(b) / c);

    cout << total << endl;
}
