#include<iostream>
using namespace std;

 
class Dequeue{
     
    public:
    int size;
    int front;
    int rear;
    int* arr;

    Dequeue( int size){   
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

   bool insertAtFront(int data){
         
          if( (rear + 1) % size == front){
            return false;
          }

          if(front == -1){
            front = rear = 0;
          }

          else{
            front = (front - 1 + size) % size;
          }
        arr[front] = data;
   }

   bool insertAtLast(int data){
            
       if( (rear + 1) % size == front){
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

   bool deleteFront(){
      
        if( front == -1){
            return false;
        }

        if( front == rear){
            front = rear = -1;
        }

        else{
            front = (front + 1) % size;
        }
      return true;

   }

   bool deleteLast(){
           
    if( front == -1){
        return false;
    }

    if( front == rear){
        front = rear = -1;
    }
else{
     rear = (rear -1 + size ) % size;
}

return true;

   }

   int getFront(){
           
         if( front == -1){
            return -1;
         }
         int ans = arr[front];
         return ans;

   } 
   
   int getRear(){
       
    if( rear == -1){
             return -1;
    }
    int ans = arr[rear];
    return ans;

   }

   bool isEmpty(){
     
    if( front == -1){
        return true;
    }
    return false;

   }

   bool isFull(){
      
    if( (rear +1 ) % front == rear){
        return true;
    }
    return false;
         
   }



};



int main(){


  Dequeue q(10);



    return 0;
}