#include <bits/stdc++.h>

using namespace std;

string generate(string& s, vector<int> marks) {
    if(marks.size() == 0) {
        return "";
    }

    string ans = "";
    bool zeroskipped = false;
    for(int i = 0; i < s.size(); i++) {
        if(marks[0] == i || (marks.size() > 1 && marks[1] == i)) {
            continue;
        }

        if(ans.size() == 0 && s[i] == '0') {
            zeroskipped = true;
            continue;
        }

        ans.push_back(s[i]);
    }

    if(ans.size() == 0) {
        if(zeroskipped) {
            return "0";
        }
        else {
            return "";
        }
    }
    else {
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    int total = 0;
    for(auto i : s) {
        total += i - '0';
        total %= 3;
    }

    if(total == 0) {
        cout << s << endl;
        return 0;
    }

    vector<int> mark1;
    vector<int> mark2;
    if(total == 1) {
        // Mark a one
        for(int i = s.size()-1; i >= 0; i--) {
            if((s[i]-'0') % 3 == 1) {
                mark1.push_back(i);
                break;
            }
        }

        // Mark 2 twos
        for(int i = s.size()-1; i >= 0; i--) {
            if((s[i]-'0') % 3 == 2) {
                mark2.push_back(i);
                if(mark2.size() == 2) {
                    break;
                }
            }
        }
    }

    if(total == 2) {
        // Mark a two
        for(int i = s.size()-1; i >= 0; i--) {
            if((s[i]-'0') % 3 == 2) {
                mark1.push_back(i);
                break;
            }
        }

        // Mark 2 ones
        for(int i = s.size()-1; i >= 0; i--) {
            if((s[i]-'0') % 3 == 1) {
                mark2.push_back(i);
                if(mark2.size() == 2) {
                    break;
                }
            }
        }
    }

    string ans1 = generate(s, mark1);
    string ans2 = generate(s, mark2);

    if(ans2.size() > ans1.size()) {
        ans1.swap(ans2);
    }

    if(ans1.size() > 0) {
        cout << ans1 << endl;
    }
    else {
        cout << -1 << endl;
    }
}
