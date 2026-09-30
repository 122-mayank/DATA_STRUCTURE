#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&arr , int size){

    for(int i = 0 ; i < size ; i++){
         cout << arr[i] <<" ";
    }
    cout << endl;

}

int partition(vector<int>&arr , int st ,int end){

    int pivot = arr[st];
    int count = 0;
    for(int i = st + 1 ; i <= end ; i++){
          if(arr[i] <= pivot){
             count = count + 1;
          }
    }

    int pivotIndex = st + count;
    swap(arr[st], arr[pivotIndex]);

    int i = st;
    int j = pivotIndex + 1;

    while( i < pivotIndex && j <= end){

        while(i < pivotIndex && arr[i] <= pivot ){
            i++;
        }
        while(j <= end && arr[j] > pivot){
            j++;
        }
        if(i < pivotIndex && j <= end){
            swap(arr[i++] , arr[j++]);
        }
    }

    return pivotIndex;

}

void quickSort(vector<int>&arr , int st , int end){

    if(st >= end) return;

    int pi = partition(arr , st , end);
    quickSort(arr , st , pi - 1);
    quickSort(arr , pi + 1, end);
}

int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    vector<int>arr(size);
    cout <<"Insert the elements"<< endl;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    cout <<"Before Sorted Array "<< endl;
    print(arr , size);

    quickSort(arr , 0 , size - 1);
    cout << endl;

    cout <<"After Sorted Array "<< endl;
    print(arr , size);

}