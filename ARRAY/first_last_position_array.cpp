#include<iostream>
#include<array>
#include<vector>
using namespace std;


int firstPosition(int*arr , int target , int size){
            
      int st = 0;
      int end = size - 1;
      int ans = -1;
      
      while( st <= end){

        int mid = st+(end-st) / 2;

        if( arr[mid] == target){
               ans = mid;
                end = mid - 1;
        }

      else if( target <  arr[mid]){
            end = mid-1;
        }

        else{
            st = mid +1;
        }

      }
  return ans;

}


int lastPosition(int*arr , int target , int size){
  
      int st = 0;
      int end = size - 1;
      int ans = -1;
      
      while( st <= end){

        int mid = st+(end-st) / 2;

        if( arr[mid] == target){
               ans = mid ;
                st = mid + 1;
        }

       else if( target <  arr[mid]){
            end = mid-1;
        }

        else{
            st = mid +1;
        }

      }
  return ans;

}


int main(){

int arr[] = { 1 , 2, 2, 2, 3 , 3 , 3, 3, 3, 3, 3 , 4 , 4 , 4 , 5, 6, 7 ,8 , 9};
int size = sizeof(arr) / sizeof(arr[0]);
int target;
cout <<"Enter the target element: "<<endl;
cin >> target;

int fpos = firstPosition(arr , target , size);
cout <<"Element occurence at first position: "<<fpos<<endl;

int lpos = lastPosition(arr , target , size);
cout<<"Element at last position: "<<lpos<<endl;

}