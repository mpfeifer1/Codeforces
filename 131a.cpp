#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool lock = true;
    for(int i = 1; i < s.length(); i++) {
        if(islower(s[i])) {
            lock = false;
        }
    }
    if(lock) {
        for(auto i : s) {
            if(isupper(i)) {
                cout << (char)tolower(i);
            }
            if(islower(i)) {
                cout << (char)toupper(i);
            }
        }
        cout << endl;
    }
    else {
        cout << s << endl;
    }
}
