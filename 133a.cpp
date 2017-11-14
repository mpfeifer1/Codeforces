#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    for(auto i : s) {
        if(i == 'H' || i == 'Q' || i == '9') {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
