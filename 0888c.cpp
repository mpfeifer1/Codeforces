#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int best = 100000;
    for(int i = 'a'; i <= 'z'; i++) {
        int dist = 0;
        int maxdist = 0;
        for(auto c : s) {
            if(c != i) {
                dist++;
            }
            else {
                dist = 0;
            }
            maxdist = max(dist, maxdist);
        }

        best = min(maxdist, best);
    }

    cout << best + 1 << endl;
}
