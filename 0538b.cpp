#include <bits/stdc++.h>

using namespace std;

bool zero(string& s) {
    bool works = true;
    for(auto i : s) {
        if(i != '0') {
            works = false;
        }
    }
    return works;
}

int extract(string& s) {
    int n = 0;
    for(auto& i : s) {
        n *= 10;
        if(i > '0') {
            n++;
            i--;
        }
    }
    return n;
}

int main() {
    string s;
    cin >> s;

    vector<int> ans;

    while(!zero(s)) {
        int i = extract(s);
        ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
