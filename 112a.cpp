#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    for(auto& i : a) {
        i = tolower(i);
    }
    for(auto& i : b) {
        i = tolower(i);
    }

    if(a == b) {
        cout << "0" << endl;
    }
    if(a < b) {
        cout << "-1" << endl;
    }
    if(a > b) {
        cout << "1" << endl;
    }
}
