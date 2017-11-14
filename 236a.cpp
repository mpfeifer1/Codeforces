#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> c;

    for(auto i : s) {
        c.insert(i);
    }

    if(c.size() % 2 == 1) {
        cout << "IGNORE HIM!" << endl;
    }
    else {
        cout << "CHAT WITH HER!" << endl;
    }
}
