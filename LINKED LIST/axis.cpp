//Prims Algorithm

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int , list<int>>adj;

    void addEdge(int u ,int v){
         adj[u].push_back(v);
         adj[v].push_back(u);
    }

};

int main(){

    int vertices;
    cout <<"Enter the number of vertices: "<< endl;
    cin >> vertices;

    int edges;
    cout <<"Enter the number of edges: "<< endl;
    cin >> edges;

    int u , v;
    Graph g;

    for(int i = 1 ; i <= edges ; i++){
        cout <<"Enter the "<< i <<" edge: ";
        cin >> u >> v;
        g.addEdge(u , v);
    }


    



    


}