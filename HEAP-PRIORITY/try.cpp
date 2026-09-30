#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(const pair<int,int>&a , const pair<int,int>&b){
          if (a.second > b.second){
              return true;
          }
          if (a.second == b.second){
               if(a.first > b.first){
                    return true;
               }
          }

          return false;
    }
};

int main(){

    //Min heap
    priority_queue<pair<int , int> ,
     vector<pair<int, int>> , compare>pq;

     pq.push({2 , 4});
     pq.push({7, 9});
     pq.push({3 , 2});
     pq.push({8 , 11});
     pq.push({9 , 14});
     pq.push({8 , 4});
     pq.push({5 , 6});

     while(!pq.empty()){
         auto top = pq.top();
         cout << top.first <<" , "<< top.second << endl;
         pq.pop();
     } 
}