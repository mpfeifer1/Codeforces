#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int find(ll* d, int a) {
    if(d[a] < 0) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(ll* d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    ll val = d[a] + d[b] + 1;
    d[a] = val;
    d[b] = a;
}

ll val(ll* d, int a) {
    a = find(d, a);
    return -d[a] - 1;
}

int main() {
    int n;
    cin >> n;

    ll d[100001];
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        d[i] = -(d[i]+1);
    }

    stack<int> q;
    stack<ll> a;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        q.push(temp-1);
    }

    bool seen[100001];
    for(int i = 0; i < n; i++) {
        seen[i] = false;
    }

    ll best = 0;
    while(!q.empty()) {
        int curr = q.top();
        q.pop();

        a.push(best);
        seen[curr] = true;

        if(curr > 0 && seen[curr-1]) {
            join(d, curr-1, curr);
        }
        if(curr+1 < n && seen[curr+1]) {
            join(d, curr+1, curr);
        }

        best = max(best, val(d, curr));
    }

    while(!a.empty()) {
        cout << a.top() << endl;
        a.pop();
    }
}
