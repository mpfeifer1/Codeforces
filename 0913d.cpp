#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll t;

struct question {
    int req;
    ll time;
    int index;
};

bool cmp(question& q1, question& q2) {
    return q1.time < q2.time;
}

bool calculate(vector<question>& v, int target) {
    ll left = t;
    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(count == target) {
            break;
        }
        if(v[i].req < target) {
            continue;
        }
        if(left - v[i].time >= 0) {
            left -= v[i].time;
            count++;
        }
    }

    if(count >= target) {
        return true;
    }
    return false;
}

void generate(vector<question>& v, int target) {
    vector<question> ans;

    ll left = t;
    for(int i = 0; i < v.size(); i++) {
        if(ans.size() == target) {
            break;
        }
        if(v[i].req < target) {
            continue;
        }
        if(left - v[i].time >= 0) {
            left -= v[i].time;
            ans.push_back(v[i]);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.index << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> t;

    int idx = 1;
    vector<question> v(n);
    for(auto& i : v) {
        cin >> i.req >> i.time;
        i.index = idx;
        idx++;
    }
    sort(v.begin(), v.end(), cmp);

    int lo = 0;
    int hi = n+2;
    int mi;
    while(hi - lo > 1) {
        mi = (hi + lo) >> 1;
        if(calculate(v, mi)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << lo << endl;
    generate(v, lo);
}
