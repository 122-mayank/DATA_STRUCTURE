#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<tuple<int, int, int>> edgesList; // store edges (u, v, w)

    void addEdge(int u, int v, int w) {
        edgesList.push_back({u, v, w});
    }

    void bellmanFord(int n, int src) {
        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;

        // Step 1: Relax all edges (n - 1) times
        for (int i = 1; i <= n - 1; i++) {
            for (auto [u, v, w] : edgesList) {
                if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Check for negative weight cycle
        bool negCycle = false;
        for (auto [u, v, w] : edgesList) {
            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                negCycle = true;
                break;
            }
        }

        // Step 3: Output results
        if (negCycle) {
            cout << "Negative weight cycle detected!\n";
        } else {
            cout << "Vertex\tDistance from Source(" << src << ")\n";
            for (int i = 1; i <= n; i++) {
                cout << i << "\t";
                if (dist[i] == 1e9)
                    cout << "INF";
                else
                    cout << dist[i];
                cout << endl;
            }
        }
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Graph g;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    g.bellmanFord(n, src);

    return 0;
}
