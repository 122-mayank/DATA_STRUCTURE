#include<bits/stdc++.h>
using namespace std;

int makingsequence(vector<int>&nums){

    
    int currlen = INT_MIN;      
    for( int i = 0 ; i < nums.size() - 1 ; i++){
                
        int value = nums[i];
        vector<int>ans;

         // step-1 : for left elements to the current element
         for( int j = 0 ; j < i ; j++){
             
                if( value > nums[j]){
                     int op = nums[j];
                     ans.push_back(op);
                }

         }
             ans.push_back(value);

         // step-2 : for right elemens to the current element
          for(int k = i+ 1; k < nums.size() ; k++){
              
               if( value < nums[k]){
                    int op2 = nums[k];
                    ans.push_back(op2);
               }
             
          }
            
        
         int idx = 0;
        //step-3 : value set to -1;
        for( int k = 0 ; k < ans.size() -1; k++){
             
                   if( ans[k] > ans[k+1] ){
                          ans[k+1] = -1;
                   }
        
        }

        vector<int>res;
        for( int j = 0 ; j < ans.size() ; j++){
              if( ans[j] != -1){
                 res.push_back(ans[j]);
              }
        } 
        
        vector<int> res2 = res;
        int size = res.size();
        sort(res.begin() , res.end());

        if( res2 == res){
             currlen = max(currlen , size);
        }

    }
     

  return currlen;

}

int main(){

    int size ;
    cout <<"Enter the size of the array: ";
    cin >> size;

    vector<int>nums(size);

    cout<<"Enter the elements: "<<endl;
    for( int i = 0 ;  i < size ; i++){
         cin >> nums[i];
    }

    
   int ans =  makingsequence(nums);
   cout << "The longest incresing subsequence is : "<< ans << endl;


}