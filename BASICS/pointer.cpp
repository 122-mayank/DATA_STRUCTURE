#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>a= {1, 2, 3, 4, 5};

    vector<int>b= {1, 2, 3, 6, 7};

           int i = 0;
           int j = 0;
           
           vector<int>ans;
          
           while( i < a.size() && j < b.size()){
               
                if(a[i] < b[j]){
                    
                    if(ans.empty()){
                        ans.push_back(a[i]);
                    }
                    else{
                        if(ans.back()!= a[i]){
                            ans.push_back(a[i]);
                        }
                    }
                    i = i + 1;
                    
                }
                else if(a[i] > b[j]){
                    
                    if(ans.empty()){
                        ans.push_back(b[j]);
                    }
                    else{
                        if(ans.back() != b[j]){
                           ans.push_back(b[j]);
                        }
                    }
                    
                    j = j + 1;
                  
                }
                else{
                    
                    if(ans.empty()){
                        ans.push_back(a[i]);
                    }
                    
                    else if(ans.back() != a[i]){
                        ans.push_back(a[i]);
                    }
                    
                    j = j + 1;
                    i = i + 1;
                    
                    
                }
               
           }
           
           
           //traverse to the remaining in first arary
           while(i < ans.size()){
               if(ans.back() != a[i]){
                ans.push_back(a[i]);
               }
               i = i + 1;
           }
           
           while(j < ans.size()){
                if(ans.back() != b[j]){
                  ans.push_back(b[j]);
               }
               j = j + 1;
           }

           //print the answer
           for(int i = 0 ; i < output.size() ; i++){
             cout << output[i] << endl;
           }


}