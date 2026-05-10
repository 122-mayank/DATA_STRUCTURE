#include<iostream>
using namespace std;




int binarySearch(int*arr , int size , int target){
           
    int st = 0;
    int end = size -1;

    while( st <= end){
             
        int mid = st + ( end - st)/2;

        if( arr[mid] == target){
            return mid;
        }
      
        else if( arr[mid] > target){
            end  = mid-1;
        }

        else{
            st = mid+1;
        }
    }

  return -1;

}

int main(){

int size;   

cout<<"Enter the size of array: "<<endl;
cin >> size;

int*arr = new int[size];

cout<<"Enter the elements: "<<endl;
for(int i = 0 ; i < size ; i++){
    cin >> arr[i];
}

int target;
cout<<"Enter the target element: "<<endl;
cin >> target;

int ans = binarySearch(arr , size , target);

if(ans != -1){
    cout << "Element found at index : "<<ans<<endl;
}

else{
    cout <<"Element not found!!"<<endl;
}




}