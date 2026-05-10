#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>&st , int element){

if(st.empty()){
    st.push(element);
    return ;
}

int el = st.top();
st.pop();
solve(st,element);
st.push(el);



}
   

int main(){


int arr[8] = {21,32,56,78,12,31,22,87};

    stack<int> st;

    for(int i = 0 ; i < 8; i++){

        st.push(arr[i]);
        
    }
  
    solve(st , 7);

    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
 

}