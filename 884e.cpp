#include <bits/stdc++.h>

using namespace std;

int n, m;
string s1, s2;
int d[200000];

int find(int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d[a]);
    return d[a];
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) {
        return;
    }

    d[b] = a;
}

void tobin(string& s, string& out) {
    out = "";

    for(auto i : s) {
        if(i == '0') {
            out += "0000";
        }
        if(i == '1') {
            out += "0001";
        }
        if(i == '2') {
            out += "0010";
        }
        if(i == '3') {
            out += "0011";
        }
        if(i == '4') {
            out += "0100";
        }
        if(i == '5') {
            out += "0101";
        }
        if(i == '6') {
            out += "0110";
        }
        if(i == '7') {
            out += "0111";
        }
        if(i == '8') {
            out += "1000";
        }
        if(i == '9') {
            out += "1001";
        }
        if(i == 'A') {
            out += "1010";
        }
        if(i == 'B') {
            out += "1011";
        }
        if(i == 'C') {
            out += "1100";
        }
        if(i == 'D') {
            out += "1101";
        }
        if(i == 'E') {
            out += "1110";
        }
        if(i == 'F') {
            out += "1111";
        }
    }
}

pair<int,int> process() {
    int ones = 0;
    int merge = 0;

    // Count ones
    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] == '1') {
            ones++;
        }
    }

    // Count merge ups
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] == '1' && s2[i] == '1' && (find(i) != find(i+m))) {
            merge++;
            join(i, i+m);
        }
    }

    // Count merge lefts
    for(int i = 1; i < s1.length(); i++) {
        if(s2[i] == '1' && s2[i-1] == '1' && (find(i) != find(i-1))) {
            merge++;
            join(i-1, i);
        }
    }

    return {ones, merge};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int ones = 0;
    int merges = 0;

    string temp;
    cin >> temp;
    tobin(temp, s2);

    for(auto i : s2) {
        if(i == '1') {
            ones++;
        }
    }

    memset(d, -1, m*4);

    for(int i = 1; i < s2.size(); i++) {
        if(s2[i] == '1' && s2[i-1] == '1') {
            merges++;
            join(i-1, i);
        }
    }

    for(int i = 0; i < n-1; i++) {
        // Shift d set right
        for(int i = 0; i < m; i++) {
            if(d[i] != -1) {
                d[i + m] = d[i] + m;
            }
            else {
                d[i + m] = -1;
            }
            d[i] = -1;
        }

        // Get new string
        string next;
        cin >> next;
        s1 = s2;
        tobin(next, s2);

        // Find connected components
        pair<int,int> p = process();
        ones += p.first;
        merges += p.second;
    }

    cout << ones-merges << endl;
}
