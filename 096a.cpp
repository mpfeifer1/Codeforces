#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int o = 0;
    int z = 0;

    bool danger = false;

    for(auto c : s) {
        if(c == '1') {
            z = 0;
            o++;
        }
        if(c == '0') {
            o = 0;
            z++;
        }

        if(z == 7 || o == 7) {
            danger = true;
        }
    }

    if(danger) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
