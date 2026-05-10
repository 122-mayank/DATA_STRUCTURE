#include<bits/stdc++.h>
using namespace std;

class graph{
       public:
        
      unordered_map<int , list<int>>adj;
      void edge(int u , int v , bool direction){
                 
        adj[u].push_back(v);
        
        //undirected graph
        if(direction == 0){
              adj[v].push_back(u);
        }
        

      }   

       void print(){
        
          for(auto i : adj){
              cout << i.first <<" -> ";
              for(auto j : i.second){
                   cout << j << ",";
              }
              cout << endl;
          }

       }



};

int main(){

  int n;
  cout <<"Enter the no of nodes: ";
  cin >> n;


  int  m;
  cout <<"Enter the no of edges: ";
  cin >> m;
 
   graph g;
  for(int i = 0 ; i < m ; i++){
     
      int u , v;
      cin >> u >> v;
      g.edge(u,v,0);

  }
  
  g.print();

}
