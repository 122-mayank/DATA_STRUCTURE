#include<iostream>
#include<stack>
using namespace std;



void sortedStack(stack<int>&st , int x){

   if(st.empty() || ( !st.empty() && st.top() < x)){
    st.push(x);
    return;
   }

  int n = st.top();
  st.pop();

  sortedStack(st , x);

  st.push(n);
 

}

void solve(stack<int>&st){

if(st.empty()){
    return ;
}


int num = st.top();
st.pop();

solve(st);

sortedStack(st , num);


}

int main(){


    int arr[8] = {21,32,56,78,12,31,22,87};

    stack<int> st;

    for(int i = 0 ; i < 8; i++){

        st.push(arr[i]);
        
    }
  solve( st);

  while(!st.empty()){
    cout << st.top() <<" ";
    st.pop();
}

}