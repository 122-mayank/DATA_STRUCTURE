#include<bits/stdc++.h>
using namespace std;

class Graph{
      
    public:
    unordered_map<int , list<pair<int,int>>>adj;
    
    void addEdge(int u , int v , int weight){

        pair<int,int>p = make_pair(v , weight);
        adj[u].push_back(p);
         
    }

    void printadj(){
          for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                 cout <<"("<<j.first <<","<<j.second<<"), ";
            }
            cout << endl;
          }
    }

    void topoSort(stack<int>&s , unordered_map<int , 
        bool>&visited , int src){
         
        visited[src] = true;

        for(auto i : adj[src]){
            if(!visited[i.first]){
              topoSort(s , visited, i.first);
            }
        }
        s.push(src);     
    }

    void getShortestPath(int src , vector<int>&dist  , stack<int>&st){
              dist[src] = 0;

              while(!st.empty()){
                 int top = st.top();
                 st.pop();

                 if(dist[top] != INT_MAX){
                       for(auto i : adj[top]){
                         if(dist[top] + i.second < dist[i.first]){
                              dist[i.first] = dist[top]  + i.second;
                         }
                       }
                    }
                 }
               }

           };

int main(){

      int v;
      cout <<"Enter the number of vertices: "<< endl;
      cin >> v;

      int e;
      cout <<"Enter the number of edges: "<< endl;
      cin >> e;

     Graph g;
      for(int i = 0 ; i < e ; i++){
         int u , v , weight;
         cin >> u >> v >> weight;
         g.addEdge(u,v,weight);
      }
      cout << endl;
      g.printadj();

      stack<int>s;
      int src = 1;
      unordered_map<int , bool>visited;
      for(int i = 0 ; i < v ; i++){
            if(!visited[i]){
           g.topoSort(s , visited  , i);              
        }
      }
      

      vector<int>dist(v);
      for(int i = 0 ; i < v ; i++ ){
             dist[i] = INT_MAX;
      }

        g.getShortestPath(src , dist ,s);

        cout << "Answer is : " <<endl;
        for(int  i =0 ; i < dist.size() ; i++){
            cout << dist[i] <<" ";
        }

        cout << endl;
     
}