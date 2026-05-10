#include<iostream>
using namespace std;

int getPivot(int *arr , int size){

    int st = 0;
    int end = size - 1;

    while( st < end){
              
        int mid = st + ( end - st )/2;

        if( arr[0] <= arr[mid]){
             
            st = mid + 1;

        }

        else{
            end = mid;
        }

    }
     return st;
}

int binarySearch(int *arr , int st , int end , int target){

        
    while( st <= end){

     int mid = st + ( end - st)/2;

     if( target == arr[mid]){
        return mid;
     }

    else  if(target < arr[mid]){
          end = mid -1;
     }
     else {
        st = mid +1;
     }

    }
 return  -1;

}

int main(){

int size;
cout <<"Enter the size of array: "<<endl;
cin >> size;

cout <<"Insert Elements: "<<endl;
int*arr = new int[size];

for( int i = 0 ; i < size ; i++){
    cin >> arr[i];
}
int target;
cout <<"Enter the target element: "<<endl;
cin >> target;

int pivot = getPivot(arr , size);

if( target >= arr[pivot] && target <= arr[size-1] ){
      int ans = binarySearch(arr , pivot , size-1 , target);
      cout << ans << endl;
}
else{
      int ans = binarySearch(arr , 0 , pivot -1 , target);
      cout << ans <<endl;
}

}