#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int total = 0;
    string pat = "13579aeiou";
    for(auto i : s) {
        if(pat.find(i) != string::npos) {
            total++;
        }
    }

    cout << total << endl;
}
