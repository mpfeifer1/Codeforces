#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }

    for(int i = 2; i < sqrt(n) + 1; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < 1000; i++) {
        if(!isprime(n * i + 1)) {
            cout << i << endl;
            return 0;
        }
    }
}
