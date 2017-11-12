#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<char> seen;
    vector<char> l;

    vector<vector<int>> graph;
    graph.resize(26, vector<int>(26, 0));

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(seen.count(s[0]) == 0) {
            l.push_back(s[0]);
        }
        seen.insert(s[0]);

        for(int j = 1; j < s.size(); j++) {

            seen.insert(s[j]);
            if(seen.count(s[0]) == 0) {
                l.push_back(s[0]);
            }

            graph[s[j]-'a'][s[j-1]-'a'] = 1;
        }
    }

    int size = 26;

    unordered_set<int> skip;
    vector<char> output;
    for(int i = 0; i < size; i++) {
        vector<int> zerocol;

        // Count all the zero rows
        for(int j = 0; j < size; j++) {
            // If this letter needs to be skipped, skip it
            if(skip.count(j) > 0) {
                continue;
            }

            // Check if this col is all zeros
            bool allzero = true;
            for(int k = 0; k < size; k++) {
                if(graph[j][k] == 1) {
                    allzero = false;
                }
            }

            // If it is, add it to the list
            if(allzero) {
                zerocol.push_back(j);
            }
        }

        if(zerocol.size() == 0) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            output.push_back(zerocol[0] + 'a');
            skip.insert(zerocol[0]);
            for(int i = 0; i < size; i++) {
                graph[i][zerocol[0]] = 0;
            }
        }
    }

    for(auto i : output) {
        if(seen.count(i) > 0) {
            cout << i;
        }
    }
    cout << endl;
}
