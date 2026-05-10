#include<bits/stdc++.h>
using namespace std;

class graph{
      public:
      unordered_map<int , list<int>> adj;
      void addedge(int u , int v){
        
         //for directed graph
         adj[u].push_back(v);

      }
      
      void topologicalSort(int node , unordered_map<int , bool>&visited , stack<int>&st ){
                  
             visited[node] = true;

             for(auto neigh : adj[node]){
                    
                if(!visited[neigh]){
                     topologicalSort(neigh , visited , st);
                }

             }

             st.push(node);

      }



};


int main(){

    int v;
    cout<<"Enter the no of vertices: ";
    cin >> v;

    int edge;
    cout <<"Enter the no of edges: ";
    cin >> edge;

   graph g;
   for(int i = 1 ; i <= edge ; i++){
           int u , v;
           cin >> u >> v;
           g.addedge(u , v );
   } 


   stack<int>st;
   unordered_map<int , bool> visited;
   //topological Sort
   for(int i = 1 ;  i <= v ; i++){
         if(!visited[i]){
              g.topologicalSort(i , visited , st);
         }
   }

   vector<int>ans;
   while(!st.empty()){
       ans.push_back(st.top());
       st.pop();
   }
   cout <<"Topological Sort of DFS: "<< endl;
   for(int i = 0 ; i < ans.size() ; i++){
         cout << ans[i] <<" ";
   }

   cout << endl;



}