#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    vector<int> count(26, 0);
    for(auto i : s) {
        count[i-'a']++;
    }

    int ptr = 0;
    reverse(s.begin(), s.end());
    string t, u;
    while(s.size() > 0 || t.size() > 0) {
        while(!t.empty() && t.back() <= 'a' + ptr) {
            u.push_back(t.back());
            t.pop_back();
        }

        while(count[ptr] > 0) {
            if(s.back() <= 'a' + ptr) {
                t.push_back(s.back());
                s.pop_back();
                count[ptr]--;
                break;
            }

            t.push_back(s.back());
            count[s.back()-'a']--;
            s.pop_back();
        }

        if(count[ptr] == 0) {
            ptr++;
        }

        if(ptr >= 26) {
            break;
        }
    }

    while(!t.empty()) {
        u.push_back(t.back());
        t.pop_back();
    }

    cout << u << endl;
}
