

#include<bits/stdc++.h>
using namespace std;


void sortedInsert(stack<int>&st , int num){



    if(st.empty() || (!st.empty() && st.top() < num)){
        st.push(num);
        return;
    }


    int n = st.top();
    st.pop();


    sortedInsert(st , num);
    st.push(n);


}

void sortStack(stack<int>&st){

     if(st.empty()){
         return;
     }

     int num = st.top();
     st.pop();

     sortStack(st);

     sortedInsert(st , num);

}


int main(){

    stack<int>st;

    int n;
    cout <<"Enter the number of elements: "<< endl;
    cin >> n;

    int data;

    for(int i = 1 ; i <= n ; i++){

        cout <<"Enter the "<< i <<" data: ";
        cin >> data;

        st.push(data);

    }


    sortStack(st);

    vector<int>ans;
    while(!st.empty()){

        ans.push_back(st.top());
        st.pop();

    }

    reverse(ans.begin() , ans.end());

    cout <<"Sorted Stack: "<< endl;
    for(int i = 0 ; i < ans.size() ;i++){
        cout << ans[i] <<" ";
    }




}

























                      //element add at bottom in stack
//  #include<iostream>
//  #include<stack>
//  #include <algorithm>
//  #include<vector>
//  using namespace std;


//  void solve(stack<int>&st , int value){

//      if(st.empty()){
//          st.push(value);
//          return;
//      }

//      int num = st.top();
//      st.pop();

//      solve(st , value);
//      st.push(num);
//  }


//  int main(){

//      stack<int>st;
//      int n;
//      cout<<"Enter the number of elements: "<< endl;
//      cin >> n;

//      int data;


//      for(int i = 1 ; i<= n ; i++){

//            cout <<"Enter the "<< i <<" data: ";
//            cin >> data;

//            st.push(data);
//      }

//      int value;
//      cout <<"Enter the value: ";
//      cin >> value;

//      solve(st , value);

//      vector<int>ans;
//      while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//      }


//      cout <<"Printing the answer: "<< endl;
//      for(int i = 0; i < ans.size() ;i++ ){
//          cout << ans[i] << " ";
//      }

//  }


                        //  delete middle from stack
// / #include<bits/stdc++.h>
// using namespace std;

// void deletemiddlefromStack(stack<int>&st , int count , int size){

//           if(count == size/2){
//              st.pop();
//              return;
//           }

//           int num = st.top();
//           st.pop();

//           deletemiddlefromStack(st , count+1 , size);

//           st.push(num);


// }



// int main(){

//     stack<int>st;

//     int n;
//     cout <<"Enter the number of elements to insert in stack: "<< endl;
//     cin >> n;

//      //pushing to stack
//      int data;
//      for(int i = 1 ; i <= n ; i++){
//             cout <<"Enter the "<< i <<" data: ";
//             cin >> data;

//             st.push(data);
//      }

//      deletemiddlefromStack(st , 0 , n);

//      //Prinitng the latest stack
//      cout <<"Delete the middle ele from stack: "<< endl;
//      while(!st.empty()){
//          cout << st.top() <<" ";
//          st.pop();
//      }




// }






                //reverse an string using stack
// #include<bits/stdc++.h>
// #include<stack>
// using namespace std;


// string reverse(string s){

//      stack<char>st;
//      for(int i = 0 ; i < s.length() ; i++){
//           st.push(s[i]);
//      }

//      string ans="";
//      while(!st.empty()){

//          char ch = st.top();
//          ans = ans + ch;
//          st.pop();

//      }

//      return ans;

// }



// int main(){

//     string s;
//     cout <<"Enter the string: "<< endl;
//     getline(cin , s);

//     string ans =reverse(s);
//     cout <<"Reverse string:"<< ans <<endl;


// }




//                                     //Implementation of Stack using Array

// // #include <bits/stdc++.h>
// // using namespace std;

// // class Stack {
// // public:
// //     int top = -1;
// //     int size;
// //     int *arr;

// //     Stack(int size) {
// //         this->size = size;
// //         arr = new int[size];
// //     }

// //     void push(int value) {
// //         if (top == size - 1) {
// //             cout << "Stack Overflow!" << endl;
// //             return;
// //         }
// //         top++;
// //         arr[top] = value;
// //     }

// //     int pop() {
// //         if (top == -1) {
// //             cout << "Stack Underflow!" << endl;
// //             return -1;
// //         }
// //         int ele = arr[top];
// //         arr[top] = -1;
// //         top--;
// //         return ele;
// //     }

// //     void display() {
// //         cout << "Displayed Elements: " << endl;
// //         for (int i = top; i >= 0; i--) {
// //             cout << arr[i] << " ";
// //         }
// //         cout << endl;
// //     }

// //     ~Stack() {
// //         delete[] arr;
// //     }
// // };

// // int main() {
// //     Stack st(10);

// //     st.push(12);
// //     st.push(13);
// //     st.push(34);
// //     st.push(56);
// //     st.push(67);

// //     cout << endl;
// //     st.display();

// //     int returnvalue = st.pop();
// //     cout << endl << "Popped: " << returnvalue << endl;

// //     cout << endl;
// //     st.display();
// // }

//                         //Implementation of Stack using Linked List
// #include <bits/stdc++.h>
// using namespace std;

// class Stack {
// public:
//     class Node {
//     public:
//         int data;
//         Node* next;

//         Node(int data) {
//             this->data = data;
//             this->next = nullptr;
//         }
//     };

//     Node* top = nullptr;

//     // Constructor with initial element
//     Stack(int data) {
//         top = new Node(data);
//     }

//     // Push operation
//     void push(int data) {
//         Node* newnode = new Node(data);
//         newnode->next = top;
//         top = newnode;
//     }

//     // Pop operation
//     int pop() {
//         if (isEmpty()) {
//             cout << "Stack Underflow! Nothing to pop." << endl;
//             return -1;
//         }
//         Node* temp = top;
//         int poppedValue = temp->data;
//         top = top->next;
//         delete temp;  // free memory
//         return poppedValue;
//     }

//     // Peek / Top operation
//     int peek() {
//         if (isEmpty()) {
//             cout << "Stack is empty!" << endl;
//             return -1;
//         }
//         return top->data;
//     }

//     // Check if empty
//     bool isEmpty() {
//         return top == nullptr;
//     }

//     // Display all elements
//     void display() {
//         Node* temp = top;
//         while (temp != nullptr) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }

//     // Destructor → deletes all nodes to prevent memory leak
//     ~Stack() {
//         while (!isEmpty()) {
//             pop();
//         }
//         cout << "Stack memory freed." << endl;
//     }
// };

// int main() {
//     int data;
//     cout << "Enter the head data: ";
//     cin >> data;

//     Stack st(data);

//     st.push(20);
//     st.push(40);
//     st.push(60);
//     st.push(30);

//     cout << "Displaying elements: " << endl;
//     st.display();

//     cout << "Top element (peek): " << st.peek() << endl;

//     cout << "Popping: " << st.pop() << endl;
//     cout << "After pop: ";
//     st.display();

//     cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

//     return 0;


// }
