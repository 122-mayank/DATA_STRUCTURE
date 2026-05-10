#include<bits/stdc++.h>
using namespace std;

class graph{
      public:
      
       unordered_map<int , list<int>> adj;
       void addedge(int u , int v){
             adj[u].push_back(v);
             adj[v].push_back(u);
       }
       
       void bfs(unordered_map<int , bool> &visited , 
        unordered_map<int , int>&parent , int s){
            
             queue<int>q;
             q.push(s);
             visited[s] = true;
             parent[s] = -1;

             while(!q.empty()){
                   
                int front = q.front();
                q.pop();

                for(auto i : adj[front]){
                      if(!visited[i]){
                          visited[i] = true;
                          parent[i] = front;
                          q.push(i);
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
    cout <<"Enter the no of edges: ";
    cin >> edges;

    graph g;
    cout<<"Enter the edges(u,v): ";
    for(int i = 1 ; i <= edges ; i++){
        int u , v;
        cin >> u >> v;
         g.addedge(u,v);
    }
    
    unordered_map<int , bool>visited;
    unordered_map<int , int> parent;

    int s , d;

    cout <<"Enter the source node: ";
    cin >> s;

    cout <<"Enter the destination node: ";
    cin >> d;

    g.bfs(visited ,parent , s );

    vector<int>ans;

    int currnode = d;
    ans.push_back(d);
    while(currnode != s){
         currnode = parent[currnode];
         ans.push_back(currnode);
    }

    reverse(ans.begin() , ans.end());
    //Printing the arary
    cout<<"Shortest Path: "<<endl;
    for(int i = 0 ; i <ans.size() ; i++){
          cout << ans[i] << " ";
    }
      cout << endl;
}