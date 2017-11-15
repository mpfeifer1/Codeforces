#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n >> n;

    string s;
    cin >> s;

    while(n--) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i-1] == 'B' && s[i] == 'G') {
                swap(s[i-1], s[i]);
                i++;
            }
        }
    }

    cout << s << endl;
}
