#include <bits/stdc++.h>

using namespace std;

int main() {
    char c1, c2;
    char r1, r2;
    cin >> c1 >> r1 >> c2 >> r2;

    vector<string> command;

    for(int i = 0; i < 7; i++) {
        string cmd = "";
        if(c1 > c2) {
            cmd.push_back('L');
            c1--;
        }
        if(c2 > c1) {
            cmd.push_back('R');
            c2--;
        }

        if(r1 > r2) {
            cmd.push_back('D');
            r1--;
        }
        if(r2 > r1) {
            cmd.push_back('U');
            r2--;
        }

        if(cmd == "") {
            break;
        }

        command.push_back(cmd);
    }

    cout << command.size() << endl;
    for(auto i : command) {
        cout << i << endl;
    }
}
