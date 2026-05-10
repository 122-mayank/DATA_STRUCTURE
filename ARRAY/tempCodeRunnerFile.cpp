    }
    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[v] < rank[u])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};
struct Edge {
    int u, v, wt;
};
bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    int mstWeight = 0;
    vector<Edge> result;
    for (auto it : edges) {
        if (dsu.findParent(it.u) != dsu.findParent(it.v)) {
            mstWeight += it.wt;
            result.push_back(it);
            dsu.unionSet(it.u, it.v);
        }
    }
    cout << "MST Weight: " << mstWeight << endl;
    cout << "Edges in MST:\n";
    for (auto it : result) {
        cout << it.u << " -- " << it.v << "  weight = " << it.wt << endl;
    }
    return 0;
}


