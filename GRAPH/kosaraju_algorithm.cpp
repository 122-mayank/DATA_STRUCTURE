#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int , list<int>>adj;

    void addEdge(int u , int v){
         adj[u].push_back(v);

    }

    void dfs(int node , stack<int>&st,unordered_map<int , bool>&vis){
              vis[node] = true;

              for(auto neigh : adj[node]){

                 if(!vis[neigh]){
                     dfs(neigh , st , vis);
                 }


              }

            //   cout << node <<" ";
              st.push(node);

    }

    void transpose(unordered_map<int , bool>&vis , unordered_map<int ,list<int>>&transGraph , int n){

        for(int i = 0 ; i < n ;i++){
            vis[i] = 0;
            for(auto nbr : adj[i]){
                 transGraph[nbr].push_back(i);
            }
        }
    }

    void revdfs(int node , unordered_map<int , bool>&vis ,unordered_map<int ,list<int>>&transGraph ){

         vis[node] = true;
         for(auto nbr : transGraph[node]){
             if(!vis[nbr]){
                 revdfs(nbr , vis , transGraph);
             }
         }
    }

    
};
int main(){


    int n;
    cout <<"Enter the number of vertices: "<< endl;
    cin >> n;

    int edges;
    cout <<"Enter the number of edges: "<< endl;
    cin >> edges;

    int u , v;
    Graph g;

    for(int i = 0 ; i < edges ; i++){
            cin >> u >> v;
            g.addEdge(u,v);
    }

    //doing topological Sort
     stack<int>st;
     unordered_map<int , bool> vis;
     for(int i = 0 ; i < n ; i++){
         if(!vis[i]){
             g.dfs(i , st , vis);
         }
     }

     //transpose the graph
     int count = 0;
     unordered_map<int ,list<int>> transGraph;
     g.transpose(vis, transGraph,n);

     while(!st.empty()){
         int top = st.top();
         st.pop();

         if(!vis[top]){
              count++;
              g.revdfs(top, vis , transGraph);
         }

    }

    cout <<"Number of Strongly Connected Component in the Graph: "<< endl;
    cout << count << endl;



}