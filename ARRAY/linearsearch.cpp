#include<iostream>
using namespace std;

int linearSearch(int arr[] , int size , int target){


    for( int i = 0 ; i < size ; i++){
         
        if( arr[i] == target){
            return i;
        }

    }
          
   return -1;
}


int main(){

cout <<"Enter the size of arary: "<<endl;
int size ;
cin >> size;

int*arr = new int[size];

cout <<"Enter the array elements: "<<endl;
for( int  i = 0 ; i < size ; i++){
     cin >> arr[i];
}
int target;
cout <<"Enter the search element: "<<endl;
cin >> target;
 
int ans = linearSearch(arr ,size , target);
if(ans){
    cout << "The element found at index is: "<< ans <<endl;
}

else{
    cout <<"The element is not found!!"<<endl;
}

}