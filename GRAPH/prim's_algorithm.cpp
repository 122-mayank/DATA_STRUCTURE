#include<bits/stdc++.h>
using namespace std;

class Graph{
     public:
      
     unordered_map<int , list<pair<int,int>> > adj;
     void addEdge(int u , int v , int w){
         
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

     }


     int SpanningTree( vector<int>&key , vector<bool>&Mst , 
        vector<int>&parent , int v ){
             
        for(int i = 0 ; i < v ; i++){
        
         int u ;
         int mini = INT_MAX;
         
         //1st step - Find the minimum of all the nodes
         for(int j = 0 ; j < v ; j++){
              if(Mst[j] == false && key[j] < mini){
                       u = j;
                       mini = key[j];
              }
         }
          
         Mst[u] = true;

         //2nd step - tracK the MST and parent
         for(auto neigh : adj[u]){
              int v = neigh.first;
              int w = neigh.second;

              if( Mst[v] == false && key[v] > w){
                     parent[v] = u;
                     key[v] = w;
              }
         }
         

     }


    //  vector<pair<pair<int,int>,int>> result;
    //  for(int i = 1 ; i < n ; i++ ){
    //       result.push_back({{parent[i],i},key[i]});
    //  }
    int sum = 0;
    for(int i = 1 ; i < v ; i++){
          sum += key[i];       
    }

    return sum;

     }
     
};


int main(){

     int v;
     cout <<"Enter the number of vertices: ";
     cin >> v;

     int edges;
     cout <<"Enter the number of edges: ";
     cin >> edges;

     Graph g;
     cout <<"Enter the (u , v & w): ";
     for(int i = 0 ; i < edges ; i++){
           int u , v , w;
           cin >> u >> v>> w;
           g.addEdge(u , v, w);
     }


     vector<int>key(v);
     vector<bool>Mst(v);
     vector<int>parent(v);

     //Intialize all the vectors
     for(int i = 0 ; i < v; i++){
             parent[i] = -1;
             Mst[i] = false;
             key[i]= INT_MAX;
     }

     int src = 0;
     parent[src] = -1;
     key[src] = 0;

    int ans =  g.SpanningTree(key , Mst , parent , v);
    cout <<"The weight of MST is: "<< ans << endl;
     
}