#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    while(n--) {
        string s;
        cin >> s;

        if(s[1] == '+') {
            ans++;
        }
        if(s[1] == '-') {
            ans--;
        }
    }

    cout << ans << endl;
}
