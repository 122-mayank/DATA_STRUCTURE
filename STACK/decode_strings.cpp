#include<bits/stdc++.h>
using namespace std;

string solve(string s){


     stack<char>st;

    //push in to stack
    for(int i = 0 ; i < s.size() ; i++){

          if((s[i] >= '0' && s[i] <= '9' ) || (s[i] >= 'a' && s[i] <= 'z')){
               st.push(s[i]);
          }

    }


    string ans="";
    while(!st.empty()){

        char top = st.top();
        // st.pop();

        if(top >= 'a' && top <= 'z'){

               string temp = "";
               while(!(top >= '0' && top <= '9')){
                        temp = temp + top;
                        top = st.top();
                        st.pop();
               }

               reverse(temp.begin() , temp.end());

        }

       else if(top >= '0' && top <= '9'){

           string temp ="";
           while(!st.empty() && !(top >= 'a' && top <= 'z')){
           temp = temp + top;
            top = st.top();
            st.pop();
           }

           int value = temp - '0';

        int count = value;
        while(count != 0){
             ans = ans + temp;
             count--;
        }


    }


}

return ans;


}


int main(){

     string s;

     cout <<"Enter the string s: "<< endl;
     getline(cin, s);


     string value = solve(s);
     cout << value << endl;
    //  cout << s << endl;


}