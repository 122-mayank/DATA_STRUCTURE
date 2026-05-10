//  doing the quick Sort Problem

#include<bits/stdc++.h>
using namespace std;

//choosing middle as pivot

int partition(vector<int>&arr , int st , int end){

    int mid = st + (end - st) / 2;
    int pivot = arr[mid];

    swap(arr[mid] , arr[end]);

    int i = st - 1;

    for(int j = st ; j < end ; j++){

         if(arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
         }

    }

    swap(arr[i+1] , arr[end]);

    return i + 1;
}

void print(vector<int>&arr){

    //doing the print
    for(int i = 0 ; i < arr.size() ; i++){

         cout << arr[i] <<" ";

    }
}


void quickSort(vector<int>&arr  , int st , int end){

    if(st >= end){
        return;
    }

    int pi = partition(arr , st , end);
    quickSort(arr , st , pi - 1);
    quickSort(arr , pi + 1, end);
}


int main(){


    int size;
    cout <<"Enter the size "<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the array elements "<< endl;
    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }

    quickSort(arr , 0 , size - 1);

    cout <<"Sorted Array "<< endl;
    print(arr);

}