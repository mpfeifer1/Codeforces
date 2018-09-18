#include <iostream>

using namespace std;

bool beautiful(int n) {
    bool works = true;
    bool ones = false;

    int o = 0;
    int z = 0;

    while(n > 0) {
        if(n % 2 == 0) {
            z++;
            if(ones) {
                return false;
            }
        }
        else {
            o++;
            ones = true;
        }
        n >>= 1;
    }

    return works && (o == z+1);
}

int main() {
    int n;
    cin >> n;

    for(int i = n; i > 0; i--) {
        if(n % i == 0) {
            if(beautiful(i)) {
                cout << i << endl;
                return 0;
            }
        }
    }
}
