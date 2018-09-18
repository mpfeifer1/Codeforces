#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 0, d = 0, u = 0, r = 0;

    while(n--) {
        char c;
        cin >> c;
        if(c == 'L') {
            l++;
        }
        if(c == 'R') {
            r++;
        }
        if(c == 'U') {
            u++;
        }
        if(c == 'D') {
            d++;
        }
    }

    cout << (min(l, r) + min(u, d)) * 2 << endl;
}
