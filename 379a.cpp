#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int total = 0;
    int left = a;
    int used = 0;

    while(left > 0 || used >= b) {
        if(used >= b) {
            used -= b;
            left++;
        }

        left--;
        used++;
        total++;
    }

    cout << total << endl;
}
