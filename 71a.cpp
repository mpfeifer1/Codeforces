#include <iostream>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        string s;
        cin >> s;

        if(s.length() > 10) {
            cout << s[0] << s.length() - 2 << s[s.size()-1] << endl;
        }
        else {
            cout << s << endl;
        }
    }
}
