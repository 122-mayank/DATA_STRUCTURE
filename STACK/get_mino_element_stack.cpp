#include<iostream>
#include<stack>
using namespace std;


class SpecialStack{
 
    public:
    stack<int>s;
    int mini;


 

    void push(int data){
            
        if(s.empty()){
            s.push(data);
            mini = data;
        }

        else{
         
            if( data < mini){
                s.push(2 * data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }

        }
         

    }

    int pop(){
         
        if(s.empty()){
            return -1;
        }
         int curr = s.top();
         s.pop();

        if( curr > mini){
            return curr;
        }        
        
        else{
             int prevMin = mini;
             int val = 2 * mini - curr;
             mini = val;
             return prevMin;
        }
    }

    int top(){

           if(s.empty()){
            return -1;
           }

           else{
                  if( s.top() > mini){
                    return s.top();
                  }
                  else{
                    return mini;
                  }
           }

    }

   bool isempty(){
        return s.empty();

   }
  
   int getMini(){

        if(s.empty()){
               return -1;
        }
      return mini;
   }

};

int main(){
 
    SpecialStack st;

    st.push(5);
    st.push(3);
    st.push(2);
    st.push(8);
    st.push(4);

    cout << st.pop() <<endl;
    cout << st.pop() <<endl;

    st.push(12);
    st.push(23);

    cout<< st.top() <<endl;
    cout<< st.getMini() <<endl;

   return 0;

}