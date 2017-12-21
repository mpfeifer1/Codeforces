#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, int> m;

    int n;
    cin >> n;
    string s;
    cin >> s;

    // Count characters
    for(auto i : s) {
        m[i]++;
    }

    string ans;
    vector<char> evens;
    vector<char> odds;

    // Count even/odds
    for(auto i : m) {
        if(i.second % 2 == 1) {
            odds.push_back(i.first);
            i.second--;
        }

        for(int j = 0; j < i.second/2; j++) {
            evens.push_back(i.first);
        }
    }

    // Move some evens over to odds to make palindrome work
    while(odds.size() > 0 && evens.size() > 0 && evens.size() % odds.size() != 0) {
        odds.push_back(evens.back());
        odds.push_back(evens.back());
        evens.pop_back();
    }

    // If no odd counts
    if(odds.size() == 0) {
        cout << 1 << endl;
        for(auto i : evens) {
            cout << i;
        }
        reverse(evens.begin(), evens.end());
        for(auto i : evens) {
            cout << i;
        }
        cout << endl;
        return 0;
    }

    // Print answer
    int o = odds.size();
    cout << o << endl;
    int num = evens.size() / odds.size();
    for(int i = 0; i < o; i++) {
        string temp;
        for(int i = 0; i < num; i++) {
            temp.push_back(evens.back());
            evens.pop_back();
        }

        cout << temp;
        cout << odds.back();
        reverse(temp.begin(), temp.end());
        cout << temp << " ";
        odds.pop_back();
    }
    cout << endl;

}
