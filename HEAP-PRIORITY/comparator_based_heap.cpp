#include<bits/stdc++.h>
using namespace std;

struct minCompare{
    bool operator()(const pair<int , int>&a , const pair<int , int>&b){
        if(a.second == b.second){
            return a.first > b.first;
        }
         return a.second > b.second ;
    }
};

int main(){

    //building min heap

    priority_queue<pair<int , int> , vector<pair<int , int>> , minCompare>pq;

    pq.push({0 , 2});
    pq.push({3 , 5});
    pq.push({8 , 9});
    pq.push({2 , 7});
    pq.push({1 , 5});

    while(!pq.empty()){
         auto top = pq.top();
         pq.pop();

         cout << top.first <<" , " << top.second << endl;
    }


}