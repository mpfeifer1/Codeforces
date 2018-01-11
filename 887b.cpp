#include <bits/stdc++.h>

using namespace std;

struct die {
    int s[6];
};

bool solve(die& d1, die& d2, int target) {
    for(auto i : d2.s) {
        if(i == target) {
            return true;
        }
    }
    for(auto i : d1.s) {
        if(i == target) {
            return true;
        }
    }

    int hi = target / 10;
    int lo = target % 10;

    bool works1 = false;
    for(auto i : d1.s) {
        if(i == hi){
            works1 = true;
        }
    }

    bool works2 = false;
    for(auto i : d2.s) {
        if(i == lo){
            works2 = true;
        }
    }

    return (works1 && works2);
}

bool possible(vector<die>& d, int target) {
    if(d.size() == 1) {
        for(int i = 0; i < 6; i++) {
            if(d[0].s[i] == target) {
                return true;
            }
        }
        return false;
    }

    if(d.size() == 2) {
        return solve(d[0], d[1], target) ||
               solve(d[1], d[0], target);
    }

    if(d.size() == 3) {
        return solve(d[0], d[1], target) ||
               solve(d[0], d[2], target) ||
               solve(d[1], d[0], target) ||
               solve(d[1], d[2], target) ||
               solve(d[2], d[0], target) ||
               solve(d[2], d[1], target);
    }
}

int main() {
    int n;
    cin >> n;

    vector<die> dice(n);
    for(auto& i : dice) {
        for(int j = 0; j < 6; j++) {
            cin >> i.s[j];
        }
    }

    for(int i = 1; i <= 1000; i++) {
        if(!possible(dice, i)) {
            cout << i-1 << endl;
            return 0;
        }
    }
}
