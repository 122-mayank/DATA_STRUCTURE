#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(12);
    pq.push(13);
    pq.push(32);
    pq.push(21);
    pq.push(31);
    
    

   cout <<"Element at the top : "<< pq.top() << endl;
   pq.pop();

   cout <<"Element at the top: "<< pq.top() << endl;

   cout << "Size: "<< pq.size() << endl;


   priority_queue<int , vector<int> , greater<int>> minheap;
   minheap.push(43);
   minheap.push(21);
   minheap.push(9);
   minheap.push(32);
   minheap.push(65);


   cout << minheap.top() << endl;




}