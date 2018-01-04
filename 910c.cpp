#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)10000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Take in input
    ll n;
    cin >> n;
    vector<string> str(n);
    unordered_set<char> begin;
    for(auto& i : str) {
        cin >> i;
        begin.insert(i.front());
        reverse(i.begin(), i.end());
    }

    // Get weight of each char
    vector<ll> weight(10, 0);
    for(auto i : str) {
        for(ll j = 0; j < i.size(); j++) {
            weight[i[j]-'a'] += pow(10, j);
        }
    }

    // Prepare permutation
    vector<char> v;
    for(ll i = 'a'; i <= 'j'; i++) {
        v.push_back(i);
    }

    ll best = inf;
    do {
        // Skip invalid
        if(begin.count(v[0]) > 0) {
            continue;
        }

        // Calculate cost
        ll cost = 0;
        for(ll i = 0; i < 10; i++) {
            cost += weight[v[i] - 'a'] * i;
        }

        best = min(best, cost);
    } while(next_permutation(v.begin(), v.end()));

    cout << best << endl;
}
