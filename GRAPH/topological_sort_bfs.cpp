// It is used only in DAG (Directed Acyclic Graph)

#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addedge(int u, int v) {
        adj[u].push_back(v);
    }

    void findindegree(vector<int>& indegree) {
        for (auto i : adj) {
            for (auto j : i.second) {
                indegree[j]++;
            }
        }
    }

    void topologicalSort(unordered_map<int, bool>& visited,
                         vector<int>& ans,
                         queue<int>& q,
                         vector<int>& indegree) {

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (auto neigh : adj[front]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
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

    for (int i = 1; i <= edge; i++) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }

    // indegree array
    vector<int> indegree(v + 1, 0);
    g.findindegree(indegree);

    // push all nodes with indegree 0
    queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    unordered_map<int, bool> visited;
    vector<int> ans;

    // only call once
    g.topologicalSort(visited, ans, q, indegree);

    // print result
    cout << "Topological Sort (BFS/Kahn’s Algorithm): ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
