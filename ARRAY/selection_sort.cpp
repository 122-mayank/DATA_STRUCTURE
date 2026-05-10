#include<iostream>
using namespace std;



void selectionSort(int *arr , int size){

     int i , j;
     for( i = 0 ;  i < size ; i++){
        int min_index = i;
        for( j = i + 1 ; j < size ; j++){
            
            if(arr[min_index] > arr[j]){
                  min_index = j;
            } 

        }
        swap(arr[min_index] , arr[i]);
     }

}


void print(int *arr , int size){
  
      for( int i = 0 ; i < size ; i++){
        cout << arr[i] <<" ";
      }
      cout <<endl;
  

}

int main(){

int size;
cout <<"Enter the size of the array: "<<endl;
cin >> size;
cout << endl;

int *arr = new int[size];
cout<<"Enter the array elements: "<<endl;
for( int i = 0 ; i < size ; i++){
    cin >> arr[i];
}
cout << endl;

cout<<"Before Sorted Array"<<endl;
print(arr , size);
selectionSort(arr , size);
cout << endl;
cout <<"After Sorted Array"<<endl;
print(arr , size);



}