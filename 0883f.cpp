#include <bits/stdc++.h>

using namespace std;

string simplify(string s) {
    string out;

    while(!s.empty()) {
        char c = s.back();
        s.pop_back();

        if(c == 'u') {
            out.push_back('o');
            out.push_back('o');
        }
        else if(c == 'k' && out.back() == 'h') {
            continue;
        }
        else {
            out.push_back(c);
        }
    }

    reverse(out.begin(), out.end());
    return out;
}

int main() {
    int n;
    cin >> n;

    unordered_set<string> seen;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s = simplify(s);
        seen.insert(s);
    }

    cout << seen.size() << endl;
}
