#include <bits/stdc++.h>

using namespace std;

bool operator<(const pair<int,int>& p1, const pair<int,int>& p2) {
    return p1.first < p2.first && p1.second > p2.second;
}

// Returns an array with the indexes of the LIS
template <class T>
vector<int> LIS(vector<T>& v) {
    vector<int> p(v.size(), -1);
    vector<int> t(v.size(), 0);

    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }

    vector<int> ans;
    for(int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    v.erase(unique(v.begin(),v.end()),v.end());

    n = v.size();
    vector<int> left;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[i] == v[j]) {
                left.push_back(-j);
            }
        }
    }

    int sub = 0;
    if(left.size() > 0) {
        sub = LIS(left).size();
    }
    cout << (n-1) - sub << endl;
}
