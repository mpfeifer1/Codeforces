#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int a=0, b=0, c=0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'Q') {
            c += b;
            a++;
        }
        if(s[i] == 'A') {
            b += a;
        }
    }

    cout << c << endl;
}
