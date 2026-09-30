#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>&arr , int size){

    for(int i = 0 ; i < size ; i++){
        cout << arr[i] <<" ";
    }   
}


void bubbleSort(vector<int>&arr , int size){

    for(int i = 0 ; i < size ; i++){
         
         bool swapped = false;
         for(int j = 0 ; j < size - i - 1 ; j++){
              if(arr[j] > arr[j+1]){
                   swap(arr[j] , arr[j+1]);
                  swapped = true;
              }
         }
         cout <<"Swaps Count "<< endl;
         if(swapped == true){
             break;
         }
         
    }
    
}

int main() {

    int size;
    cout <<"Enter the array of size"<< endl;
    cin >> size;

    vector<int>arr(size);
    cout <<"Enter the array elements"<< endl;

    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    cout <<"Before Sorted"<< endl;
    print(arr , size);

    bubbleSort(arr , size);

    cout << endl;

    cout <<"After Sorted"<< endl;
    print(arr , size);
    
}