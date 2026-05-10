#include<bits/stdc++.h>
using namespace std;

class graph{
      public:
      
      unordered_map<int , list<int>>adj;
      
      //for the directed garaph
      void addedge(int u , int v){
        
           adj[u].push_back(v);

      }

      bool detectCycle(int node , unordered_map<int , bool>&visited,  unordered_map<int , bool> &dfsvisited ){

              visited[node] = true;
              dfsvisited[node] = true;

              for(auto neigh : adj[node]){
                    
                     if(!visited[neigh]){
                          if(detectCycle(neigh , visited , dfsvisited)){
                             return true;
                          }
                     }


                     else if( dfsvisited[neigh] == true ){
                          return true;
                     }

                    }
                 dfsvisited[node]  = false;
                 return false;   

      }



};


int main(){

    int v;
    cout <<"Enter the number of vertices: "<< endl;
    cin >> v;

    int edge;
    cout <<"Enter the number of edges: " << endl;
    cin >> edge;
    
    graph g;

    for(int i = 1 ; i <= edge ; i++){
          int u , v;
          cin >> u >> v;
         
          g.addedge(u , v);
          
    }
    unordered_map<int , bool> visited;
    unordered_map<int , bool> dfsvisited;
    bool ans = false;
    // for all components
    for(int i = 1 ; i <= v ;i++){
           if(!visited[i]){
            if( g.detectCycle( i , visited  , dfsvisited )){
                 ans = true;
                 break;
            }
              
           }
    }

    if(ans){
         cout <<"Cycle is present !!" << endl;
    }

    else{
         cout << "Cycle is not present!!" << endl;
    }


}