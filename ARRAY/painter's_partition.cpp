#include<iostream>
using namespace std;

bool isPossible(int*arr , int mid , int m , int size){

 int studentCount = 1;
 int pageSum = 0;

 for( int i = 0 ; i < size ; i++){
     
       if( pageSum + arr[i] <= mid){
        pageSum += arr[i];
       }

       else{
               
             studentCount++;
             if(studentCount > m || arr[i] > mid){
                return false;
             }
             else{
                 pageSum = 0;
                 pageSum += arr[i];
             }

       }
 }
 return true;

}

int binarySearch(int*arr , int m , int size){

    int st = 0;
    int sum = 0;
    for( int i = 0 ; i < size ; i++){
        sum += arr[i];
    }

    int end = sum;
    int ans;

    while( st <= end){
            
             int mid = st + (end - st) / 2;

             if(isPossible(arr , mid , m , size)){
                   ans = mid;
                   end = mid - 1;
             }
             else{
                st = mid + 1;
             }

    }
 
      return ans;
}

int main(){

    int size;
    cout <<"Enter the size of the arary: "<<endl;
    cin >> size;

    int *arr = new int[size];

    cout <<"Enter the array elements: "<<endl;
    for( int i =  0 ; i < size ; i++){
        cin >> arr[i];
    }

    int m ;
    cout <<"Enter the number of the students: "<<endl;
    cin >> m;

    int ans = binarySearch(arr , m ,size);
    cout <<"Answer is: "<<ans <<endl;



}