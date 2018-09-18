#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

struct warrior {
    vector<int> friends;
    int degree;
};

int main() {
    int n, m;
    cin >> n >> m;

    warrior empty;
    empty.degree = 0;

    vector<warrior> warriors(n, empty);
    vector<vector<bool>> adj;
    adj.resize(n, vector<bool>(n, false));

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        adj[n1][n2] = true;
        adj[n2][n1] = true;

        warriors[n1].friends.push_back(n2);
        warriors[n2].friends.push_back(n1);

        warriors[n1].degree++;
        warriors[n2].degree++;
    }

    int best = 2<<29;
    for(auto i : warriors) {
        for(int j = 0; j < i.friends.size(); j++) {
            for(int k = j+1; k < i.friends.size(); k++) {
                int f1 = i.friends[j];
                int f2 = i.friends[k];
                if(adj[f1][f2]) {
                    int d = i.degree + warriors[f1].degree + warriors[f2].degree - 6;
                    best = min(best, d);
                }
            }
        }
    }

    if(best != 2<<29) {
        cout << best << endl;
    }
    else {
        cout << "-1" << endl;
    }
}
