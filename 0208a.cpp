#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string ans;
    for(int i = 0; i < s.size(); i++) {
        if(i < s.size()-2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            ans.push_back(' ');
            i += 2;
        }
        else {
            ans.push_back(s[i]);
        }
    }

    cout << ans << endl;
}
