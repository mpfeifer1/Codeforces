#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    for(auto i : s) {
        if(i == '0') {
            cout << "YES" << endl;
            cout << "0" << endl;
            return 0;
        }
    }

    vector<vector<pair<bool,int>>> memo;
    memo.resize(s.size(), vector<pair<bool,int>>(8, {false,-3}));
    for(int i = 0; i < 8; i++) {
        memo[0][i].second = -4;
    }

    for(int i = 0; i < s.size(); i++) {
        int digit = (s[i] - '0') % 8;
        if(i == 0) {
            memo[0][digit].first = true;
            memo[0][digit].second = -1;
        }
        else {
            memo[i][digit].first = true;
            memo[i][digit].second = -1;

            for(int j = 0; j < 8; j++) {
                if(memo[i-1][j].first) {
                    memo[i][j].first = true;
                    memo[i][j].second = -3;

                    memo[i][(j*10+digit)%8].first = true;
                    memo[i][(j*10+digit)%8].second = j;
                }
            }
        }
    }

    // -4: skip, done
    // -3: skip, go back
    // -1: use,  done
    // (pos): use, goal is now pos

    int index = s.size()-1;
    if(memo[index][0].first) {
        string ans;
        int goal = 0;
        while(true) {
            if(memo[index][goal].second == -1) {
                ans.push_back(s[index]);
                break;
            }
            else if(memo[index][goal].second > 0) {
                ans.push_back(s[index]);
                goal = memo[index][goal].second;
            }
            else if(memo[index][goal].second == -4) {
                break;
            }

            index--;
        }

        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
