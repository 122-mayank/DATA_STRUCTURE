#include<iostream>
#include<stack>
#include<string>
using namespace std;

int longestValidParentheses(string s) {

    //edge case 
    if( s == ""){
        return 0;
    } 

    stack<char> st;
    st.push('0');
    int length = 0;
    for( int i = 0 ; i < s.size() ; i++){
         
      if( s[i] == '('){
         char ch = s[i];
         st.push(ch);
      }

      else{
          
         if( st.top() == '('){

             char ch =s[i];
             st.push(ch);
           if( !st.top() != '0'){
            st.pop();
            st.pop();
            length = length + 2;
           }

         }

      }     

    }
    
return length;

}

int main(){

string s = ")()())()()())";

int length = longestValidParentheses(s);
cout << length <<endl;


}