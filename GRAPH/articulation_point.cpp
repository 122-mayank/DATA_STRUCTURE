#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int parent, vector<int>&disc, vector<int>&low, unordered_map<int, bool> &vis, int &timer, vector<int>&ap)
    {

        vis[node] = true;
        disc[node] = low[node] = timer++;

        int child = 0;
        for (auto neigh : adj[node])
        {

            if (neigh == parent)
            {
                continue;
            }

            if (!vis[neigh])
            {
                dfs(neigh, node, disc, low, vis, timer,ap);
                low[node] = min(low[node], low[neigh]);
                if (low[neigh] >= disc[node] && parent != -1)
                {
                    ap[node] = 1;
                }
                child++;
            }

            else
            {
                low[node] = min(low[node], disc[neigh]);
            }
        }

        if (child > 1 && parent == -1)
        {
            ap[node] = 1;
        }
    }
};

int main()
{

    int v;
    cout << "Enter the number of vertices: " << endl;
    cin >> v;

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g;
    int x, y;

    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }

    vector<int> disc(v);
    vector<int> low(v);

    int parent = -1;
    int timer = 0;
    vector<int>ap(v, 0);

    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            g.dfs(i, -1, disc, low, vis, timer, ap);
        }
    }

    // Priniting the articulation points in the graph
    cout <<"Printing the articulation points in the graph: "<< endl;
    for (int i = 0; i < ap.size(); i++)
    {
        if (ap[i] != -0)
        {
            cout << i << " ";
        }
    }
}