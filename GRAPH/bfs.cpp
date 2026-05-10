#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void edge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {  // undirected
            adj[v].push_back(u);
        }
    }

    void printadjcency() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(int i, vector<int>& ans, vector<bool>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (auto neigh : adj[front]) {
                if (!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }
};

int main() {
    graph g;
    int n, m;
    cout << "Enter the no of nodes: ";
    cin >> n;
    cout << "Enter the no of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.edge(u, v, 0);  // undirected graph
    }

    g.printadjcency();
    cout << endl;

    vector<int> ans;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.bfs(i, ans, visited);
        }
    }

    cout << "BFS Traversal: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
