#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool detectCycle(int node, vector<bool>& visited, int parent) {
        visited[node] = true;

        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                if (detectCycle(neigh, visited, node)) {
                    return true;  // cycle found in subtree
                }
            }
            else if (neigh != parent) {
                // already visited but not parent → cycle
                return true;
            }
        }
        return false;
    }
};

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    graph g;
    for (int i = 0; i < edge; i++) {
        int u, vtx;
        cin >> u >> vtx;
        g.addedge(u, vtx);
    }

    vector<bool> visited(v, false);
    bool ans = false;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (g.detectCycle(i, visited, -1)) {
                ans = true;
                break;
            }
        }
    }

    if (ans) {
        cout << "Cycle is present!!" << endl;
    } else {
        cout << "Cycle is not present!!" << endl;
    }

    return 0;
}
