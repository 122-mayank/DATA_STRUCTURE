#include<iostream>
#include<stack>
using namespace std;

int main(){

    string str ="Radha Krishna";

    stack<char> st;

    for(int i = 0 ; i < str.length() ; i++){

          char ch = str[i];
          st.push(ch);

    }
    string ans="";
    while(!st.empty()){
       
        char pop_element = st.top();
        ans = ans + pop_element;
        st.pop();
    }

    cout << ans <<endl;


}