#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
 
    
stack<int> s;
int nums[5] = { 2 ,1 ,7 , 3 , 4};
s.push(-1);
vector<int> ans(5);

for( int i = 4 ; i >=0 ; i--){
      int curr  = nums[i];

      while(s.top() >= curr){
          s.pop();
      }
      ans[i] = s.top();
      s.push(curr);

}
 
for( int i = 4; i >=0; i--){
    cout << ans[i] <<" ";
}

    
}