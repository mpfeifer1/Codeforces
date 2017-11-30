#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, string> m;
    unordered_map<string, string> r;

    for(int i = 0; i < n; i++) {
        string curr, next;
        cin >> curr >> next;

        if(r.count(curr) == 0) {
            m[curr] = next;
            r[next] = curr;
            continue;
        }

        string prev = r[curr];

        r.erase(next);
        r.erase(curr);

        m[prev] = next;
        r[next] = prev;

    }

    cout << m.size() << endl;
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
}
