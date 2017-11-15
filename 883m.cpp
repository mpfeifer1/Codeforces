#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int e1 = max(abs(a-c), 1) + 1;
    int e2 = max(abs(b-d), 1) + 1;

    cout << e1 * 2 + e2 * 2 << endl;
}
