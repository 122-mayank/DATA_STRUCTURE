#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    void dfs(int node, unordered_map<int, bool>& visited, vector<int>& com) {
        visited[node] = true;
        com.push_back(node);

        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(i, visited, com);
            }
        }
    }
};

int main() {
    int v;
    cout << "Enter the no of vertices: ";
    cin >> v;

    int edge;
    cout << "Enter the no of edges: ";
    cin >> edge;

    graph g;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }

    // DFS traversal
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            vector<int> com;
            g.dfs(i, visited, com);
            ans.push_back(com);  // push component after dfs finishes
        }
    }

    // Printing the dfs traversal (connected components)
    cout << "\nConnected Components:\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
