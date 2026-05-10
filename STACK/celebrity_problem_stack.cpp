#include<iostream>
#include<stack>
#include<vector>
using namespace std;



bool knows(vector<vector<int>>&arr  , int a , int b , int n){

return arr[a][b] == 1;


}


int solve( vector<vector<int>>&arr , int n){

 stack<int> st;

 for( int i = 0 ; i < n ; i++){
      
    st.push(i);

 }

 while( st.size() > 1){

int a = st.top();
st.pop();

int b = st.top();
st.pop();

if(knows(arr , a , b , n)){
    st.push(b);
}
else{
    st.push(a);
}

 }

int candidate = st.top();


//check for row

for( int i = 0 ; i < n ; i++){
  if( arr[candidate][i] == 1 && i != candidate  ){
    return -1;
  }
}

//check for column
for( int i = 0 ; i < n ; i ++){
    if(arr[i][candidate] == 0 && i != candidate){
        return -1;
    }
}

return candidate;
}


int main(){

    vector<vector<int>>arr = {
      {1,1,0},
      {0,1,0},
      {0,1,1},

    }; 
   int n = 3;
 int ans =  solve(arr , n);

 cout << ans <<endl;


}