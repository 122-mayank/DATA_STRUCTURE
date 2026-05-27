//Dijisktra Algorithm -> O(E logE)
#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int , list<pair<int , int>>>adj;

    void addEdge(int u , int v , int w){
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }

    void dijikstra(int src , vector<int>&dist){

        //make the priority queue
        priority_queue<pair<int,int> , vector<pair<int , int>> , greater<pair<int ,int>>>pq;

        pq.push({0 , src});

        while(!pq.empty()){

            auto top = pq.top();
            int node = top.second;
            int wt_n = top.first;

            pq.pop();
            if(wt_n > dist[node]) continue;

            for(auto neigh : adj[node]){
                
                int v = neigh.first;
                int w = neigh.second;

                if(wt_n + w < dist[v]){
                     dist[v] = wt_n + w;
                     pq.push({dist[v] , v});
                }

            }


        }


    }



};

int main(){

    int vertices;
    cout <<"Enter the number of vertices"<< endl;
    cin >> vertices;

    int edges;
    cout <<"Enter the number of edges"<< endl;
    cin >> edges;

    Graph g;
    int u , v,w;
    cout <<"Enter the edge(u , v, w)"<< endl;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v >> w;
        g.addEdge(u , v,w);
    }

    vector<int>dist(vertices , INT_MAX);

    int src;
    cout <<"Enter the source node"<< endl;
    cin >> src;

    dist[src] = 0;

    g.dijikstra(src , dist );

    cout <<"Shortest Path"<< endl;
    for(int i = 0 ; i < dist.size();i++){
         cout << dist[i] <<" ";
    }


}




//Prims Algorithm --> Time Complexity : O(E logE)

// #include<bits/stdc++.h>
// using namespace std;

// class Graph{

//     public:
//     unordered_map<int , list<pair<int ,int>>>adj;

//     void addEdge(int u, int v, int w){
        
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});

//     }

//     void prims(int&sum , vector<bool>&visited , int src){

//         //make the priority queue
//         priority_queue<pair<int ,int> , vector<pair<int , int>> , greater<pair<int ,int>> >pq;

//         //wt , node
//         pq.push({0 , src});

//         while(!pq.empty()){

//             auto top = pq.top();
//             int node = top.second;
//             int wt = top.first;

//             pq.pop();

//             if(visited[node] == true) continue;

//             visited[node] = true;
//             sum = sum + wt;

//             for(auto it : adj[node]){
                
//                 int node = it.first;
//                 int edge = it.second;

//                 if(!visited[node]){
//                   pq.push({edge , node});
//                 }  

//             }


//         }


//     }


// };


// int main(){
    
//     int vertices;
//     cout <<"Enter the vertices"<< endl;
//     cin >> vertices;

//     int edges;
//     cout <<"Enter the number of edges"<< endl;
//     cin >> edges;

//     Graph g;

//     int u, v, w;
//     for(int i = 0 ; i < edges; i++){
//         cout <<"Enter the " << i <<" edge(u,v,w)" << endl;
//         cin >> u >> v >>w;
//         g.addEdge( u , v, w);
//     }

//     int sum = 0;
//     vector<bool>visited(vertices , false);

//      g.prims(sum , visited , 0);
//     cout <<"Minimum weight of MST "<< sum << endl;

// }





//Kruskal Algorithm
// #include<bits/stdc++.h>
// using namespace std;

// bool compareEdges(const vector<int>&a , const vector<int>&b){
//      return a[2] < b[2];
// }

// void makeSet(vector<int>&parent , vector<int>&rank , int vertices){

//     for(int i = 0 ; i < vertices ; i++){
//          rank[i] = 0;
//          parent[i] = i;
//     }
// }

// int findParent(int node, vector<int>&parent){

//     if(node == parent[node]){ 
//         return node;
//     }

//     return parent[node] = findParent(parent[node] , parent);
// }

// void unionSet(int u , int v , vector<int>&rank , vector<int>&parent){

//      if(rank[u] < rank[v]){
//            parent[u] = v;
//      }
//      else if(rank[v] < rank[u]){
//            parent[v] = u;
//      }
//      else{
//          parent[v] = u;
//          rank[u]++;
//      }

// }

// int main(){

//     int vertices;
//     cout <<"Enter the vertices"<< endl;
//     cin >> vertices;

//     vector<vector<int>>edges;

//     int num_edges;
//     cout <<"Enter the no of edges"<< endl;
//     cin >> num_edges;

//     int u , v , w;
//     cout <<"Enter the(u,v,w) "<< endl;
//     for(int i = 0 ; i < num_edges ; i++){
//          cin >> u >> v >> w;
//          vector<int>res;

//          res.push_back(u);
//          res.push_back(v);
//          res.push_back(w);

//          edges.push_back(res);
//     }


//     sort(edges.begin() , edges.end() , compareEdges);

//     vector<int>parent(vertices);
//     vector<int>rank(vertices);

//     makeSet(parent , rank , vertices);

//     int minwt = 0;

//     for(int i = 0 ; i < edges.size() ; i++){
        
//         int u = edges[i][0];
//         int v = edges[i][1];

//         int wt = edges[i][2];

//         u = findParent(u , parent);
//         v = findParent(v , parent);

//         if( u != v){
//             unionSet( u , v , rank , parent);
//             minwt += wt;
//         }

//     }

//     cout <<"Minimum weight of Kruskal Algorithm "<< minwt << endl;

// }