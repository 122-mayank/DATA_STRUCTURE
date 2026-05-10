#include<bits/stdc++.h>
#include<set>
using namespace std;

class Graph{
      public:
      unordered_map<int , list<pair<int,int>>> adj;

      void addedge(int u , int v , int w){
        
           adj[u].push_back(make_pair(v,w));
           adj[v].push_back(make_pair(u,w));

      }
      void getShortestPath(set<pair<int,int>>&st , vector<int>&dist){

        
            while(!st.empty()){
                  
                //fetch top
                auto top = *(st.begin());


                int distnode = top.first;
                int value = top.second;
                
                //erase the top node
                st.erase(st.begin());

                for(auto neigh : adj[value]){
                    
                    if(distnode + neigh.second < dist[neigh.first]){
                          
                        auto record = st.find(make_pair(dist[neigh.first] ,neigh.first ));

                        if(record != st.end()){
                             st.erase(record);
                        }
                        //distance update
                        dist[neigh.first]=distnode + neigh.second;
                        //record push in set
                        st.insert(make_pair(dist[neigh.first] , neigh.first));


                    }

                }

            }


      }


       
};

int main(){
       
     int v;
     cout <<"Enter the number of vertices: ";
     cin >> v;

     int edges;
     cout <<"Enter the number of edges: ";
     cin >> edges;

     Graph g;
     cout <<"Enter the edges & weights(u, v ,w): "<< endl;

     //make the adjacency list
     for(int i = 0 ; i < edges ; i++){
         int u , v , w;
         cin >> u >> v >> w;
         g.addedge(u,v,w);
     }

   //create the distance array to track the evrtices
   vector<int>dist(v);
   
   int src = 0;
   dist[src] = 0;
   set<pair<int,int>> st;

   st.insert(make_pair(0,src));

   //tarverse the distance array with value of inifinite
   for(int i = 1 ; i < dist.size() ; i++){
              dist[i] = INT_MAX;
   }

   g.getShortestPath( st , dist );

   //Printing the shortest Path
   cout <<"Shortest Path using dijisktra's algorithm: "<< endl;
   for(int i = 0 ; i < dist.size() ;i++){
     cout << dist[i] <<" ";
   }


   cout << endl;






}