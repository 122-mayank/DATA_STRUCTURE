
// kruskal algorithm

#include<bits/stdc++.h>
using namespace std;

bool compareEdges(const vector<int>& a, const vector<int>& b) {
    // a[2] and b[2] are the weights (w)
    return a[2] < b[2];
}

void makeSet(vector<int>&parent , vector<int>&rank , int v){

for(int i = 0 ; i < v ; i++){
      parent[i] = i;
      rank[i] = 0;
}

}

int findParent(vector<int>&parent , int node){

      if(parent[node] == node){
          return node;
      }

      return parent[node] = findParent(parent , parent[node]);

}

void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){

     u = findParent(parent , u);
     v = findParent(parent , v);

     if(rank[u] < rank[v]){
           parent[u] = v;
     }
     else if(rank[u] > rank[v]){
          parent[v] = u;
     }
     else{
          parent[v] = u;
          rank[u]++;
     }

}



int main(){

     int vertices;
     cout <<"Enter the number of vertices: "<< endl;
     cin >> vertices;

     //make the data structure of edges
     vector<vector<int>>edges;

     int num_edges;
     cout <<"Enter the number of edges: "<< endl;
     cin >> num_edges;

     int u , v , w;
     cout <<"Enter the (u , v, w): "<< endl;
     for(int i = 0 ; i < num_edges ; i++){

          cin >> u >> v >>w;
          vector<int>res;
          res.push_back(u);
          res.push_back(v);
          res.push_back(w);
          edges.push_back(res);
     }

     sort(edges.begin(), edges.end(), compareEdges);
     //initialization
     vector<int>parent(vertices);
     vector<int>rank(vertices);
     makeSet(parent , rank , vertices);

     int minwt = 0;

     for(int i = 0 ; i < edges.size() ; i++){

           int u = findParent(parent , edges[i][0]);
           int v = findParent(parent , edges[i][1]);
           int wt = edges[i][2];

           if(u!=v){
               minwt += wt;
               unionSet(u, v , parent , rank);
           }

     }

     cout <<"Minimum weight of Kruskal Algorithm  "<< minwt<<endl;
}