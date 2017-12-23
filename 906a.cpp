#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<char> possible;
    unordered_set<char> impossible;

    for(int i = 'a'; i <= 'z'; i++) {
        possible.insert(i);
    }

    int excessive = 0;
    bool solved = false;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        string s;
        cin >> s;

        if(c == '!') {
            if(solved) {
                excessive++;
            }
            unordered_set<char> here;
            for(auto i : s) {
                if(impossible.count(i) == 0) {
                    here.insert(i);
                }
            }
            unordered_set<char> merged;
            for(auto i : here) {
                if(possible.count(i) > 0) {
                    merged.insert(i);
                }
            }
            swap(possible, merged);
        }

        if(c == '.') {
            for(auto i : s) {
                possible.erase(i);
                impossible.insert(i);
            }
        }

        if(c == '?') {
            if(solved && i != n-1) {
                excessive++;
            }
            possible.erase(s[0]);
            impossible.insert(s[0]);
        }

        if(possible.size() == 1) {
            solved = true;
        }
    }

    cout << excessive << endl;
}
