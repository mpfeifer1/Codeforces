#include <bits/stdc++.h>

using namespace std;

int n, m;

bool stacksort(vector<int>& v) {
    stack<int> s;
    vector<int> a;

    for(auto i : v) {
        s.push(i);

        while((!s.empty() && s.top() == 1) ||
              (!s.empty() && !a.empty() && s.top() == a.back() + 1)) {
            a.push_back(s.top());
            s.pop();
        }
    }

    if(s.empty()) {
        return true;
    }
    return false;
}

void build(vector<int>& v) {
    vector<bool> seen(n+1, false);

    for(auto i : v) {
        seen[i] = true;
    }

    for(int i = 1; i < n; i++) {
        if(!seen[i] && seen[i+1]) {
            int pos = i;
            while(!seen[pos] && pos >= 1) {
                v.push_back(pos);
                pos--;
            }
        }
    }

    int pos = n;
    while(!seen[pos] && pos >= 1) {
        v.push_back(pos);
        pos--;
    }
}

int main() {
    cin >> n >> m;
    vector<int> v(m);
    for(auto& i : v) {
        cin >> i;
    }

    build(v);

    if(stacksort(v)) {
        for(auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}
