#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool works = false;

    size_t idx = s.find("AB");
    if(idx != string::npos && s.find("BA", idx+2) != string::npos) {
        works = true;
    }

    idx = s.find("BA");
    if(idx != string::npos && s.find("AB", idx+2) != string::npos) {
        works = true;
    }

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
