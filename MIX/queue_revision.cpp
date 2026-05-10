// Priority Queue (Without using STL)
#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int size;
    int *dataArr;
    int *priorityArr;
    int count;

    PriorityQueue(int size) {
        this->size = size;
        this->dataArr = new int[size];
        this->priorityArr = new int[size];
        this->count = 0;
    }

    void enqueue(int data, int priority) {
        if (count == size) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        dataArr[count] = data;
        priorityArr[count] = priority;
        count++;

        cout << "Inserted (" << data << ", P:" << priority << ")" << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        int highest = 0;
        for (int i = 1; i < count; i++) {
            if (priorityArr[i] < priorityArr[highest]) {
                highest = i;
            }
        }

        cout << "Deleted: " << dataArr[highest] << " (Priority: " << priorityArr[highest] << ")" << endl;

        for (int i = highest; i < count - 1; i++) {
            dataArr[i] = dataArr[i + 1];
            priorityArr[i] = priorityArr[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Current Queue: ";
        for (int i = 0; i < count; i++) {
            cout << "(" << dataArr[i] << ", P:" << priorityArr[i] << ") ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the Priority Queue: ";
    cin >> size;

    PriorityQueue pq(size);

    int choice, data, priority;

    while (true) {
        cout << "\n----- Priority Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority (smaller number = higher priority): ";
                cin >> priority;
                pq.enqueue(data, priority);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting Program..." << endl;
                return 0;

            default:
                cout << "Invalid Choice! Please try again.\n";
        }
    }

    return 0;
}


// Circular Queue

// #include<bits/stdc++.h>
// using namespace std;

// class CircularQueue{
//          public:
//          int size;
//          int *arr;
//          int front;
//          int rear;

//          CircularQueue(int size){
//              this -> size = size;
//              this -> arr = new int[size];
//              this -> front = -1;
//              this -> rear = -1;
//          }

//           void enqueue(int data){

//               if( (rear + 1) % size == front){
//                    cout <<"Queue is overflow!!" << endl;
//                    return;
//               }

//               if(front == -1){
//                       front = rear = 0;
//                }
//                else{
//                          rear = (rear + 1) % size;
//                }
//                   arr[rear] = data;
//                   cout << data <<" inserted sucessfully!!\n";
//         }

//           int dequeue(){

//               if(front == -1){
//                     cout <<"Queue is underflow!!" << endl;
//                     return -1;
//               }

//               int value = arr[front];

//               if(front == rear){
//                  front = rear = -1;
//               }
//               else{
//                  front = (front + 1) % size;
//               }

//               return value;

//         }

//           void display(){

//                 if (front == -1) {
//             cout << "Queue is empty!!" << endl;
//             return;
//         }

//         cout << "Displaying the data: ";
//         int i = front;
//         while (true) {
//             cout << arr[i] << " ";
//             if (i == rear) break;
//             i = (i + 1) % size;
//         }
//         cout << endl;
//           }

// };

// int main(){

//     int size;
//     cout <<"Enter the size of the circular queue: ";
//     cin >> size;

//     CircularQueue cq(size);

//     int data , a , value;

//     int choice;

//     while(1){
//         cout <<"\nBelow operations performed on queue\n1.)Enqueue the element\n2.)Dequeue the element\n3.)Display the element\n";
//         cout <<"Enter the choice: ";
//         cin >> choice;

//          switch(choice){

//             case 1:
//              cout <<"Enter the data: ";
//              cin >> data;
//             cq.enqueue(data);
//             break;

//             case 2:
//               value = cq.dequeue();
//              if(value != 0){
//              cout <<"The dequeued value is " << value << endl;
//              }
//              break;

//              case 3:
//              cq.display();
//              break;

//              default:
//              cout <<"Invalid choice!!!"<< endl;
//              cout <<"Please enter 1 to continue......."<< endl;
//              cin >> a;
//              if(a != 1){
//                  exit(0);
//              }
//          }

//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Queue {
// public:
//     int front, rear, size;
//     int *arr;

//     Queue(int size) {
//         this->size = size;
//         this->front = -1;
//         this->rear = -1;
//         arr = new int[size];
//     }

//     void enqueue(int data) {
//         if (rear == size - 1) {
//             cout << "Queue Overflow!!" << endl;
//             return;
//         }
//         if (front == -1 && rear == -1) {
//             front = 0;
//             rear = 0;
//         } else {
//             rear++;
//         }
//         arr[rear] = data;
//         cout << "Enqueued: " << data << endl;
//     }

//     void dequeue() {
//         if (front == -1 || front > rear) {
//             cout << "Queue Underflow!!" << endl;
//             return;
//         }
//         cout << "Dequeued value: " << arr[front] << endl;
//         front++;
//         if (front > rear) {
//             front = rear = -1; // Reset after last element
//         }
//     }

//     void peek() {
//         if (front == -1 || front > rear) {
//             cout << "Queue Underflow!!" << endl;
//             return;
//         }
//         cout << "Peek element: " << arr[front] << endl;
//     }

//     void display() {
//         if (front == -1 || front > rear) {
//             cout << "Queue Underflow!!" << endl;
//             return;
//         }
//         cout << "Queue elements: ";
//         for (int i = front; i <= rear; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int size, data;
//     cout << "Enter the size of the Queue: ";
//     cin >> size;

//     Queue q(size);

//     int choice;
//     while (true) {
//         cout << "\nOperations:\n1) Enqueue\n2) Dequeue\n3) Peek\n4) Display\n5) Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter data: ";
//                 cin >> data;
//                 q.enqueue(data);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 q.peek();
//                 break;
//             case 4:
//                 q.display();
//                 break;
//             case 5:
//                 cout << "Exiting..." << endl;
//                 return 0;
//             default:
//                 cout << "Invalid choice! Try again.\n";
//         }
//     }
// }
