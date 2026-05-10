#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void findIndegree(vector<int>& indegree) {
        for (auto i : adj) {
            for (auto j : i.second) {
                indegree[j]++;
            }
        }
    }

    // Returns true if cycle exists
    bool hasCycle(int vertices) {
        vector<int> indegree(vertices + 1, 0);
        findIndegree(indegree);

        queue<int> q;
        for (int i = 1; i <= vertices; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            cnt++;

            for (auto neigh : adj[front]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // If cnt != vertices → cycle exists
        return (cnt != vertices);
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycle(vertices)) {
        cout << "Cycle is present!!" << endl;
    } else {
        cout << "Cycle is not present!" << endl;
    }
    return 0;
}
