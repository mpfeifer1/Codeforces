#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int total = 0;
    while(a <= b) {
        total++;
        a *= 3;
        b *= 2;
    }

    cout << total << endl;
}
