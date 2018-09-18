#include <bits/stdc++.h>

using namespace std;

int inf = (1 << 30) - 1;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,pair<int,int>>> edges(m);
    vector<pair<int,int>> graph(m);
    vector<pair<int,int>> extra;

    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second.first;
        edges[i].second.first *= -1;
        edges[i].second.second = i;
    }
    sort(edges.begin(), edges.end());

    int c = 1;
    int d = 0;
    for(int i = 0; i < m; i++) {
        if(edges[i].second.first) {
            c++;
            graph[edges[i].second.second] = {1, c};
            if(extra.size() > 100005) {
                continue;
            }
            for(int j = 2; j < c; j++) {
                extra.push_back({j,c});
            }
        }
        else {
            if(d >= extra.size()) {
                cout << -1;
                return 0;
            }
            graph[edges[i].second.second] = extra[d];
            d++;
        }
    }

    for(auto i : graph) {
        cout << i.first << " " << i.second << endl;
    }
}
