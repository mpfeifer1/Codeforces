#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    for(auto& c : s) {
        c = tolower(c);

        if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')) {
            cout << "." << c;
        }
    }
    cout << endl;
}
