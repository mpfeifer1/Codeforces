#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> seen;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(seen[s] == 0) {
            cout << "OK" << endl;
        }
        else {
            cout << s << seen[s] << endl;
        }

        seen[s]++;
    }
}
