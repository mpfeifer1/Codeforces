#include <bits/stdc++.h>

using namespace std;

// Check word matches all guessed chars
bool matches(unordered_set<char>& g, string& pat, string& nxt) {
    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] == '*' && g.count(nxt[i]) > 0) {
            return false;
        }
        if(pat[i] != '*' && nxt[i] != pat[i]) {
            return false;
        }
    }
    return true;
}

string strip(string pat, string nxt) {
    string ret;

    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] == '*') {
            ret.push_back(nxt[i]);
        }
    }

    return ret;
}

int main() {
    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    cin >> n;

    vector<string> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // Figure out what has already been guessed
    unordered_set<char> guessed;
    for(auto i : pattern) {
        if(i != '*') {
            guessed.insert(i);
        }
    }

    // Find all strings that are OK
    vector<string> valid;
    for(auto i : v) {
        if(matches(guessed, pattern, i)) {
            valid.push_back(i);
        }
    }

    // Filter out all guessed chars
    vector<string> removed;
    for(auto i : valid) {
        removed.push_back(strip(pattern, i));
    }

    // Count characters that reveal something in all strings
    int total = 0;
    for(int i = 'a'; i <= 'z'; i++) {
        if(guessed.count(i) == 0) {
            bool works = true;
            for(auto j : removed) {
                if(j.find(i) == -1) {
                    works = false;
                }
            }
            if(works) {
                total++;
            }
        }
    }

    cout << total << endl;
}
