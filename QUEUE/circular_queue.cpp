#include<iostream>
using namespace std;

class CircularQueue{

    public:
    int size;
    int *arr;
    int front;
    int rear;

    CircularQueue(int size){
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
   
    bool enqueue(int data){

         if( (rear + 1) % size == front){
               cout <<"Queue is full"<<endl;
               return false;
         }

         if( front == -1){
            front = rear = 0;
         }

         else{
            rear = (rear + 1) % size;
         }
         arr[rear] = data;
         return true;
       
    }


    bool  dequeue(){

         int ans;

         if( front == -1){
            cout << "Queue is empty "<<endl;
            return false;
         }

         if( front == rear){
            front = rear = -1;
         }

         else{
             ans = arr[front];
             front = (front + 1) % size;
         }
        return true;
    }


   bool isEmpty(){
     
    if( front == -1){
        return true;
    }

    return false;

   }

   bool isFull(){

       if( (rear + 1) % size == front){
        return true;
       }

       return false;

   }



};


int main(){

    CircularQueue queue(10);

    cout << queue.enqueue(12) <<endl; 
    cout << queue.enqueue(2) <<endl;
    cout << queue.enqueue(34) <<endl;
    cout << queue.enqueue(23) << endl;
    cout << queue.enqueue(11) <<endl;
    cout << queue.enqueue(89) <<endl;

    cout << queue.dequeue() <<endl;
    cout <<  queue.isEmpty() <<endl;
    cout << queue.isFull() <<endl;


    


    return 0;
}