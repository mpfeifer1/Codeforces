#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool one = false;
    int total = 0;
    for(auto i : s) {
        if(i == '1') {
            one = true;
        }
        if(i == '0') {
            if(one) {
                total++;
            }
        }
    }

    if(total >= 6) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}
