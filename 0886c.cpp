#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> s;

    int total = 0;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        if(s.count(m) > 0) {
            total++;
        }
        else {
            s.insert(m);
        }
    }

    cout << total + 1 << endl;
}
