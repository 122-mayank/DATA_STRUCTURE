#include<bits/stdc++.h>
using namespace std;

class Graph{
     public:
     unordered_map<int , list<int>> adj;

     void addedge(int u , int v){

        adj[u].push_back(v);
        adj[v].push_back(u);

     }
     void print(){

        for(auto i : adj){
          cout << i.first << "-> ";
          for(auto j : i.second){
              cout << j <<" ,";
          }
          cout << endl;

        }

     }

     void dfs(int node , int parent , int&timer ,
         vector<int>&disc , vector<int>&low , vector<vector<int>>&result, unordered_map<int,bool>&vis ){

            vis[node] = true;
            disc[node] = low[node] = timer++;
            for(auto nbr : adj[node]){
                 if(nbr == parent){
                    continue;
                 }

                 if(!vis[nbr]){
                        dfs(nbr , node , timer , disc , low ,result , vis);
                        low[node] = min(low[node] , low[nbr]);
                        if(low[nbr] > disc[node]){
                            vector<int>ans;
                            ans.push_back(node);
                            ans.push_back(nbr);
                            result.push_back(ans);
                        }
                 }
                 else{
                         low[node] = min(low[node], disc[nbr]);
                 }
            }

         }

};


int main(){

     int vertices;
     cout <<"Enter the number of vertices: "<< endl;
     cin >> vertices;

     int edges;
     cout <<"Enter the number of edges: "<< endl;
     cin >> edges;

     Graph g;
     int u , v;
     for(int i = 0 ; i < edges ; i++){
                cin >> u >> v;
                g.addedge(u,v);
     }
     g.print();

     int parent = -1;
     vector<int>disc(v);
     vector<int>low(v);
     int timer = 0;
     unordered_map<int , bool>vis;

     for(int i = 0 ; i < v ; i++){
         disc[i] = -1;
         low[i] = -1;
     }

     vector<vector<int>>result;

     for(int i = 0 ; i < v ; i++){
         if(!vis[i]){
             g.dfs(i , parent , timer , disc , low ,result , vis);
         }
     }

    cout <<"Bridges edge in graph: "<< endl;
     for ( auto row : result) {
        for ( auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }





}