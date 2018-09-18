#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> actual;
    unordered_map<string, vector<string>> cluster;

    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        actual.push_back({s1,s2});

        string a = "";
        a += s1[0];
        a += s1[1];
        string b = "";
        b += s1[2];
        b += s2[0];

        cluster[a].push_back(b);
    }

    unordered_map<string, bool> side;
    bool works = true;
    for(auto i : cluster) {
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(auto j : i.second) {
            count1[j[0]-'A']++;
            count2[j[1]-'A']++;
        }

        bool side1 = true; // left side
        for(auto j : count1) {
            side1 &= (j < 2);
        }

        bool side2 = true; // right side
        for(auto j : count2) {
            side2 &= (j < 2);
        }

        bool currside;
        if(side1) {
            currside = true;
        }
        else if(side2) {
            currside = false;
        }
        else {
            works = false;
            break;
        }

        side[i.first] = currside;
    }

    if(!works) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for(auto i : actual) {
        string s1 = i.first;
        string s2 = i.second;
        string curr = "";
        curr += s1[0];
        curr += s1[1];

        // Build out string
        string out = "";
        out += s1[0];
        out += s1[1];
        if(side[curr]) {
            out += s1[2];
        }
        else {
            out += s2[0];
        }

        cout << out << endl;
    }
}
