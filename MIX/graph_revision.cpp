//shortest path using BFS

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int , list<int>>adj;
    
    void addEdge(int u , int v){
         adj[u].push_back(v);
         adj[v].push_back(u);
    }

    void shortestPath(unordered_map<int  , bool>&visited , unordered_map<int  , int>&parent , int src){

          queue<int>q;
          q.push(src);

          visited[src] = true;
          parent[src] = -1;

          while(!q.empty()){

             int front = q.front();
             q.pop();

             for(auto i : adj[front]){
                
                 if(!visited[i]){
                     visited[i] = true;
                     parent[i] = front;
                     q.push(i);
                 }

             }

          }
    }

};

int main(){

    int vertices;
    cout <<"Enter the vertices"<< endl;
    cin >> vertices;

    int edges;
    cout <<"Enter the edges"<< endl;
    cin >> edges;

    Graph g;
    int u , v;
    cout <<"Enter the edge(u ,v)"<< endl;
    for(int i = 0 ; i < edges ; i++){
         cin >> u >> v;
         g.addEdge( u , v);
    }

    int src;
    cout <<"Enter the source node"<< endl;
    cin >> src;

    int dest;
    cout <<"Enter the destination node"<< endl;
    cin >> dest;

    //make the visited array
    unordered_map<int  , bool>visited;
    
    //make the parent array
    unordered_map<int , int>parent;

    g.shortestPath(visited , parent , src);

    int currnode = dest;

    vector<int>ans;
    ans.push_back(dest);

    while(currnode != src){
          currnode = parent[currnode];
          ans.push_back(currnode);
    }

    reverse(ans.begin() , ans.end());

    cout <<"Shortest PAth "<< endl;
    for(int i = 0 ; i < ans.size() ; i++){
          cout << ans[i] <<" ";
    }

}















//cycle detection in directed graph using the DFS

// #include<bits/stdc++.h>
// using namespace std;

// class Graph{

//     public:
//     unordered_map<int , list<int>>adj;

//     //directed Graph
//     void addEdge(int u , int v){  
//         adj[u].push_back(v);
//     }

//     void topologicalSort(int node, stack<int>&st ,unordered_map<int , bool>&visited){

//        visited[node] = true;

//        for(auto neigh : adj[node]){

//         if(!visited[neigh]){
//              topologicalSort(neigh , st , visited);
//         }

//        }

//        st.push(node);


//     }

  
// };

// int main(){

//     int vertices;
//     cout <<"Enter the number of vertices"<< endl;
//     cin >> vertices;

//     int edges;
//     cout <<"Enter the number of edges"<< endl;
//     cin >> edges;

//     Graph g;

//     int u , v;
//     cout <<"Enter the edge( u, v)"<< endl;
//     for(int i = 0 ; i < edges ; i++){
//          cin >> u >> v;
//          g.addEdge( u , v);
//     }

//     unordered_map<int , bool>visited;

//     stack<int>st;
//     g.topologicalSort(0 , st , visited);

//     vector<int>ans;

//     while(!st.empty()){
//          ans.push_back(st.top());
//          st.pop();
//     }


//     cout <<"Topological Sort"<< endl;
//     for(int i = 0 ; i < ans.size() ; i++){
//         cout << ans[i] <<" ";
//     }

//     cout << endl;



// }





// //cycle detection in undirected Graph

// #include<bits/stdc++.h>
// using namespace std;

// class Graph{

//     public:
//     unordered_map<int , list<int>>adj;

//     void addEdge(int u , int v){
//           adj[u].push_back(v);
//           adj[v].push_back(u);
//     }



//     //DFS
//     bool cycle(int node,int parent ,  unordered_map<int , bool>&visited){

//          visited[node] = true;
        
//          for(auto neigh : adj[node]){
            
//              if(!visited[neigh]){
//                 if(cycle(neigh , node , visited)){
//                     return true;
//                 }
//              }

//              else if( neigh != parent){
//                    return true;
//              }

//          }

//          return false;
             

           
//     }


    // BFS
    // bool cycle(int node, unordered_map<int , bool>&visited , unordered_map<int , int>&parent){

    //      visited[node] = true;

    //      queue<int>q;
    //      q.push(node);


    //      parent[node]= -1;

    //      while(!q.empty()){

    //          int frontNode = q.front();

    //          q.pop();

    //          for(auto neigh : adj[frontNode]){
                 
    //               if(!visited[neigh]){
    //                   visited[neigh] = true;
    //                   parent[neigh] = frontNode;
    //                   q.push(neigh);
    //               }

    //               else if( neigh != parent[frontNode]){
    //                  return true;
    //               }

    //          }

    //      }

    //       return false;
    // }

// };

// int main(){

//     int vertices;
//     cout <<"Enter the number of vertices"<< endl;
//     cin >> vertices;

//     int edges;
//     cout <<"Enter the number of edges"<< endl;
//     cin >> edges;

//     Graph g;

//     int u , v;
//     cout <<"Enter the edge(u , v)"<< endl;
//     for(int i = 0 ; i < edges ; i++){
//          cin >> u >> v;
//          g.addEdge( u , v);
//     }

//     //make the visited array
//     unordered_map<int , bool>visited;
//     //make the parent array
//     // unordered_map<int , int>parent;

//     bool ans = false;

//     for(int i = 0 ; i < vertices ; i++){
        
//          if(!visited[i]){
//              if(g.cycle(i , -1 , visited )){
//                  ans = true;
//                  break;
//              }
//          }

//     }

//     if(ans){
//          cout <<"Graph contains Cycle"<< endl;
//     }
//     else{
//         cout <<"Graph does not contain Cycle"<< endl;
//     }




// }





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