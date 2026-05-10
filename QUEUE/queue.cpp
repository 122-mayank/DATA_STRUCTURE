#include<iostream>
using namespace std;

class Queue{
   
    public:
    int *arr;
    int size;
    int front;
    int rear;


    Queue(int size){
        this -> size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }


    void enqueue(int data){

        if( rear == size){
            cout <<"Overflow occurs"<<endl;
            return;
        }
        else{
            arr[rear] = data;
            rear++;
        }
            
    }


    int dequeue(){

          if( front == rear){
            cout <<"Underflow Occurs!! "<<endl;
            return 0;
          }

          else{
              
            int data = arr[front];
            front++;
            return data;
          }
    }


    bool isEmpty(){
       
        if(front == rear){
            return true;
        }
        return false;
    }

    void print(){

    for( int i = front ; i < rear ; i++){
        cout << arr[i] <<" ";
    }
         cout << endl;          
    }


};

int main(){

    Queue q1(10);
    
    q1.enqueue(12);
    q1.enqueue(23);
    q1.enqueue(45);
    q1.enqueue(34);

    cout << q1.dequeue() <<endl;
    q1.print();



   return 0;
}