#include <iostream>

using namespace std;

int main() {
    int total = 0;

    int n;
    cin >> n;

    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b + c >= 2) {
            total++;
        }
    }

    cout << total << endl;
}
