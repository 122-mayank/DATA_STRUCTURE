#include<bits/stdc++.h>
using namespace std;

//  building the max heap
int main(){


    priority_queue<int>pq;

    pq.push(10);
    pq.push(20);
    pq.push(32);


    while(!pq.empty()){

        cout << pq.top() <<" ";
        pq.pop();

    }


}