#include<bits/stdc++.h>
using namespace std;

class Graph{

     public:
     unordered_map<int, list<pair<int , int>>> adj;

     void addEdge(int u , int v , int w){

         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));

     }


     int spanningTree(int n){

    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0,0});

    int sum = 0;

    while(!pq.empty()){

        auto [wt,u] = pq.top();
        pq.pop();

        if(mst[u]) continue;

        mst[u] = true;
        sum += wt;

        for(auto neigh : adj[u]){

            int v = neigh.first;
            int w = neigh.second;

            if(!mst[v] && w < key[v]){
                key[v] = w;
                pq.push({w,v});
            }
        }
    }

    return sum;
}




};

int main(){

    int n;
    cout <<"Enter the number of vertices: ";
    cin >> n;

    Graph g;

    int edges;
     cout <<"Enter the number of edges: ";
     cin >> edges;

     int u , v ,w;

     for(int i = 0 ; i < edges ; i++){

         cin >> u >> v >> w;
          g.addEdge(u , v ,w);

     }

     vector<bool>MST(n , false);
     vector<int>parent(n ,-1);
     vector<int>key(n , INT_MAX);

     int src ;
     cout <<"Enter the source node: ";
     cin >> src;

     parent[src] = -1;
     key[src] = 0;


     int ans = g.spanningTree( n );

     cout <<"Minimum weight of spanning tree: "<< ans << endl;


}