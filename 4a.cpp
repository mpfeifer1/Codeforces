#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool works = false;
    for(int i = 1; i < n; i++) {
        if(i % 2 == 0 && (n-i) % 2 == 0) {
            works = true;
        }
    }

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
