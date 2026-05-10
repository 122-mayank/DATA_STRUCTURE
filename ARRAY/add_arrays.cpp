#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int size1 ,size2;
    cout<<"Enter the size of the 1st array: "<<endl;
    cin >> size1;

    cout<<"Enter the size of the 2nd array: "<<endl;
    cin >> size2;

    int *arr1 = new int[size1];
    cout <<"Insert the elements of the 1st array: "<<endl;
    for( int i = 0 ; i  < size1 ; i++){
        cin >> arr1[i];
    }
    
    int* arr2 = new int[size2];
    cout <<"Insert the elements of the 2nd array: "<<endl;
    for( int i = 0 ; i < size2 ; i++){
         cin >> arr2[i];
    }
    
    vector<int> ans;

    int i = size1 -1 , j = size2 - 1 , carry = 0 ;

    while( i >=0 && j >=0 ){
      
       int  sum = arr1[i] + arr2[j] + carry;
         ans.push_back(sum % 10);
        carry = sum / 10;
        i--;
        j--;   
    }


    //handle the first case
    while( i >= 0){
        int  sum = arr1[i] + carry;
        ans.push_back(sum % 10);
         carry = sum / 10;
         i--;
    } 

    //handle the second case
    while( j >= 0){
        int  sum = arr2[j] + carry;
        ans.push_back(sum % 10);
         carry = sum / 10;
         
         j--;
    } 

    //handle the third case
    while( carry != 0){
          
        ans.push_back(carry % 10);
        carry = carry / 10;

    }
  reverse(ans.begin() , ans.end());
  //printing the arrays
  cout <<"The sum of the two array is : "<<endl;
  for( int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] <<" ";
  }

 delete[] arr1;
delete[] arr2;


}