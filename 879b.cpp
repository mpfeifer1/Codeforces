#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;

    queue<ll> q;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        q.push(temp);
    }

    ll player = q.front();
    q.pop();
    ll wins = 0;

    for(ll i = 0; i < 1005; i++) {
        ll comp = q.front();
        q.pop();

        if(comp > player) {
            swap(comp, player);
            wins = 0;
        }

        q.push(comp);

        wins++;
        if(wins >= k) {
            break;
        }
    }

    cout << player << endl;
}
