#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0;
    int b = 0;
    int c = 0;
    for(int i = 0; i < n; i++) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a += a1;
        b += a2;
        c += a3;
    }

    if(a == 0 && b == 0 && c == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
