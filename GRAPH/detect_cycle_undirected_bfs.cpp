#include<bits/stdc++.h>
using namespace std;

class graph{
     public:

     unordered_map<int ,list<int>> adj;

     void addedge(int u , int v){
              
          adj[u].push_back(v);
          adj[v].push_back(u);

     }  

     bool detectCycle(int node ,vector<bool>&visited, unordered_map<int , int>&parent){

          queue<int>q;
          q.push(node);

          parent[node] = -1;
          visited[node] = true;
          while(!q.empty()){
                 
               int front = q.front();
               q.pop();

               for(auto i : adj[front]){
                    if(!visited[i]){
                         q.push(i);
                        visited[i]  = true;
                        parent[i] = front;
                    }

                   else  if(i != parent[front]){
                                return true;
                    }
               }

          }
           
          return false;

     }

};



int main(){

    int v;
    cout <<"Enter the number of vertices: ";
    cin >> v;

    int edge;
    cout <<"Enter the number of edges: ";
    cin >> edge;


    graph g;
    bool ans;
    for(int i = 0 ; i < edge ; i++){
          int u , v;
          cin >> u >> v;
          g.addedge(u , v);
    }

    //detect the cycle
     vector<bool>visited(v , false);
    unordered_map<int , int> parent;
    for(int i = 1; i <= v ; i++){
              if(!visited[i]){ 
                ans = g.detectCycle(i , visited , parent);
                 if(ans == true){
                     break;
                 }
              }
    }


    if(ans == true){
          cout << "Cycle is present!!" << endl;
    }

    else{
         cout <<"Cycle is not present!!" << endl;
    }



}