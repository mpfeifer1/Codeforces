#include <iostream>

using namespace std;

int main() {
    int garbo;
    cin >> garbo;

    string s;
    cin >> s;

    int total = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) {
            total++;
        }
    }

    cout << total << endl;
}
