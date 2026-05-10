#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>&s , int x ){
   
    if(s.empty()){
          s.push(x);
          return ;
    }
  
    int num = s.top();
    s.pop();

    insertAtBottom(s,x);

   s.push(num);


}


void solve(stack<int>&st){

    if(st.empty()){
        return ;
    }

    int num = st.top();
    st.pop();

    solve(st);

    insertAtBottom(st ,num);

}

int main(){


    int arr[8] = {21,32,56,78,12,31,22,87};

    stack<int> st;

    for(int i = 0 ; i < 8; i++){

        st.push(arr[i]);
        
    }
  solve(st);

  while(!st.empty()){
    cout << st.top() <<" ";
    st.pop();
}

}