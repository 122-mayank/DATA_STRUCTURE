#include<iostream>
// #include<stack>
using namespace std;

class Stack{
    
    //properties
    public:
    int *arr ;
    int top;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int value){
          
        if( size - top > 1){
            top++;
            arr[top] = value;
        }
        else{
            cout <<"Stack Overflow"<<endl;
        }
    }
    void pop(){
             if( top>= 0){
                top--;
             }
             else{

                cout <<"Stack Underflow"<<endl;     
            }
    }
    int peek(){
          if( top >= 0  ){
            return arr[top];
          }
          else{
            cout<<"Stack is empty"<<endl;
            return -1;
          }
    }
     
    bool isempty(){
           if( top == -1){
            return false;
           }
           else{
            return true;
           }
    }


    //behaviour
    

};

int main(){
 
    Stack st(5);
    st.push(22);
    st.push(45);
    st.push(44);
    
    cout << st.peek() <<endl;
    st.pop();
    cout << st.peek() <<endl;
    st.pop();
    cout << st.peek() <<endl;













// stack<int> s;

// s.push(45);
// s.push(32);

// // s.pop();

// cout << s.top() <<endl;
// if(s.empty()){
//     cout<<"Satck is empty"<<endl;
// }
// else{
//     cout <<"stack is not empty"<<endl;
// }






    return 0;
}