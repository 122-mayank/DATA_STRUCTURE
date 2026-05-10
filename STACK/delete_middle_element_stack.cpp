#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>&st , int count , int size){

  if( count == size/2){
         st.pop();
         return ;
  }
  int element = st.top();
  st.pop();
  solve(st , count+1,size);
  st.push(element);


}


int main(){

    int arr[8] = {21,32,56,78,12,31,22,87};

    stack<int> st;

    for(int i = 0 ; i < 8; i++){

        st.push(arr[i]);
        
    }
    int count = 0;
    solve(st , count , 8 );
    
    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
 
}