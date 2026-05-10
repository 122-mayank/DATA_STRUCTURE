#include<bits/stdc++.h>
using namespace std;

bool compareEdges(const vector<int>&a , const vector<int>&b){
     return a[2] < b[2];
}

void makeSet(vector<int>&parent , vector<int>&rank ,int vertices){
     
     for(int i = 0 ; i < vertices ; i++){
         parent[i] = i;
         rank[i] = 0;
     }

}

int findParent(vector<int>&parent ,  int node){

    if(parent[node] == node){
         return node;
    }

    return parent[node] = findParent(parent , parent[node]); //path compression
}


void unionSet(int u , int v, vector<int>&parent , vector<int>&rank){

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
    cout <<"Enter the vertices: "<< endl;
    cin >> vertices;

    int num_edges;
    cout <<"Enter the number of edges: ";
    cin >> num_edges;

    vector<vector<int>>edges;
    int u , v, w;

    cout <<"Enter the(u , v, w): "<< endl;
    for(int i = 0 ; i < num_edges ; i++){
          cin >> u >> v >> w;
          vector<int>res;
          res.push_back(u);
          res.push_back(v);
          res.push_back(w);

          edges.push_back(res);
    }

    //sort the edges
    sort(edges.begin() , edges.end() , compareEdges);

    vector<int>parent(vertices);
    vector<int>rank(vertices);

    makeSet(parent , rank , vertices);

    int minwt = 0;

    for(int i = 0 ; i < edges.size() ; i++){
        
          int u = findParent(parent , edges[i][0]);
          int v = findParent(parent , edges[i][1]);

          int wt = edges[i][2];

          if(u != v){
                 minwt +=wt;
                 unionSet(u , v, parent , rank);
          }

    }
    cout <<"Min Weight: "<< minwt << endl;





}