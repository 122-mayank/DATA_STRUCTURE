#include<bits/stdc++.h>
using namespace std;


void shellShort(int*arr , int size){

      for(int gap = size / 2 ; gap > 0 ; gap = gap /2){


          for(int i = gap ; i < size ; i++){


             int temp = arr[i];

             int j;
             for( j = i ; j >= gap && arr[j-gap] > temp ; j = j - gap){
                       arr[j] = arr[j-gap];
             }

             arr[j] = temp;

          }

      }


}

void printArray(int *arr , int size){

      for(int i = 0 ; i < size ; i++){
           cout << arr[i] <<" ";
      }

      cout << endl;

}


int main(){

     int size;
     cout <<"Enter the size of the array: ";
     cin >> size;


     int *arr = new int[size];

     cout <<"Enter the elements of the array: ";
     for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
     }


     shellShort(arr , size);
     cout <<"Sorted Array: "<< endl;
     printArray(arr , size);


}