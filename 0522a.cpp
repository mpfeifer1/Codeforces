#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Set up storage
    vector<vector<int>> adj(n*2);
    unordered_map<string, int> name;

    // Build adjacency list
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2 >> s2;

        // Make string 1 lowercase
        for(auto& j : s1) {
            j = tolower(j);
        }

        // Make string 1 lowercase
        for(auto& j : s2) {
            j = tolower(j);
        }

        // If new name, add it
        if(name.count(s1) == 0) {
            int num = name.size();
            name[s1] = num;
        }

        // If new name, add it
        if(name.count(s2) == 0) {
            int num = name.size();
            name[s2] = num;
        }

        // Add to adjacency list
        adj[name[s1]].push_back(name[s2]);
    }

    // Fill queue with every single node
    queue<int> next;
    for(int i = 0; i < name.size(); i++) {
        next.push(i);
    }

    // Run a BFS
    vector<int> v(name.size()+1, 0);
    while(!next.empty()) {
        int curr = next.front();
        next.pop();

        for(auto i : adj[curr]) {
            if(v[curr] + 1 > v[i]) {
                v[i] = v[curr] + 1;
                next.push(i);
            }
        }
    }

    // Find the best value
    int best = 0;
    for(int i = 0; i < v.size(); i++) {
        best = max(best, v[i]);
    }

    // Print the answer
    cout << best + 1 << endl;
}
