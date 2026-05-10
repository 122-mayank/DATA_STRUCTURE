//  Dijiskatra algorithm using the priority queue - min heap

#include<bits/stdc++.h>
using namespace std;

struct compare{
 public:
 bool operator()(pair<int,int>a , pair<int,int>b){
    return a.first > b.first;
 }

};
class Graph{

    public:
    unordered_map<int , list<pair<int,int>>>adj;

    void addEdge(int u , int v , int w){

         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u, w));
    }

    void getShortestPath(vector<int>&dist , priority_queue<pair<int, int> , vector<pair<int , int>> , compare>&pq){

         while(!pq.empty()){

             auto top = pq.top();
             pq.pop();

             int distnode = top.first;
             int value = top.second;

             for(auto neigh : adj[value]){

                 if(distnode + neigh.second < dist[neigh.first]){

                    dist[neigh.first] = distnode + neigh.second;
                    pq.push(make_pair(dist[neigh.first] , neigh.first));

                 }


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
    cin >>edges;

    Graph g;

    int u , v ,w;
    cout <<"Enter the ( u , v , w): "<< endl;
    for(int i = 0 ; i < edges ; i++){

        cin >> u >> v >> w;
        g.addEdge(u , v , w);

    }

    // make the distance array
    vector<int>dist(n , INT_MAX);

    int src;
    cout <<"Enter the source node: "<< endl;
    cin >> src;

    dist[src] = 0;

    //make the priority queue to store the elements
    priority_queue<pair<int, int> , vector<pair<int , int>> , compare>pq;
    pq.push(make_pair(0 , src));


    g.getShortestPath(dist , pq);

    cout <<"Shortest Distance from source node "<< endl;
    for(int i = 0 ; i < dist.size() ; i++){
          cout << i << " -> " << dist[i] << endl;
    }


}