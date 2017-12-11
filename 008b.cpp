#include <bits/stdc++.h>

using namespace std;

int inf = 10000;

int main() {
    string s;
    cin >> s;

    map<pair<int,int>, int> m;

    int x = 0;
    int y = 0;

    m[{0,0}] = inf;
    for(auto i : s) {
        if(i == 'L') {
            x--;
        }
        if(i == 'R') {
            x++;
        }
        if(i == 'U') {
            y++;
        }
        if(i == 'D') {
            y--;
        }

        m[{x,y}] = inf;
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    m[{0,0}] = 0;

    while(!q.empty()) {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        pair<int,int> curr = {currx,curry};
        pair<int,int> next;

        next = {currx-1,curry};
        if(m.count(next) > 0 && m[next] > m[curr] + 1) {
            m[next] = m[curr] + 1;
            q.push(next);
        }

        next = {currx+1,curry};
        if(m.count(next) > 0 && m[next] > m[curr] + 1) {
            m[next] = m[curr] + 1;
            q.push(next);
        }

        next = {currx,curry-1};
        if(m.count(next) > 0 && m[next] > m[curr] + 1) {
            m[next] = m[curr] + 1;
            q.push(next);
        }

        next = {currx,curry+1};
        if(m.count(next) > 0 && m[next] > m[curr] + 1) {
            m[next] = m[curr] + 1;
            q.push(next);
        }
    }

    if(m[{x,y}] == s.length()) {
        cout << "OK" << endl;
    }
    else {
        cout << "BUG" << endl;
    }
}
