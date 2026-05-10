#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

vector<int> nextSmallerElement(vector<int>& heights){
int n = heights.size();
stack<int>st;
st.push(-1);
vector<int> ans(n);
for(int i = heights.size()-1 ; i >= 0 ; i--){
        
   int curr = heights[i];
    while( st.top() != -1 && heights[st.top()] >= curr ){
        st.pop();
    }
    ans[i] = st.top();
    st.push(i);
}
return ans;
}

vector<int> prevSmallerElement(vector<int>& heights){
    int n = heights.size();
    stack<int>st;
    st.push(-1);
    vector<int> ans(n);
    for(int i = 0 ; i < heights.size() ; i++){
            
       int curr = heights[i];
        while( st.top() != -1 && heights[st.top()] >= curr ){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
    }
    
    

int largestRectangularArea(vector<int>& heights){
       
    int n = heights.size();
    
    vector<int> next(n); 
    next= nextSmallerElement(heights);

    vector<int> prev(n);
    prev = prevSmallerElement(heights);
     
    int area = INT_MIN;
    for( int i = 0 ; i < n ; i++){

      if( next[i] == -1){
        next[i] = n;
      }
      int length = heights[i];
      int width = next[i] - prev[i] - 1;
      int currArea = length * width;

      area = max(currArea , area);


    }
  return area;

}



int main(){

vector<int> heights = {2,1,5,6,2,3};
int size = heights.size();

int ans = largestRectangularArea(heights);

cout << ans <<endl;





}


