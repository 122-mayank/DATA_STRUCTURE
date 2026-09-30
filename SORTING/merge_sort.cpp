#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr , int st , int mid , int end){

    vector<int>temp;
    int left = st;
    int right = mid + 1;

    while(left <= mid && right <= end){
         if(arr[left] <= arr[right]){
             temp.push_back(arr[left]);
             left++;
         } 
         else{
             temp.push_back(arr[right]);
             right++;
         } 
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

     while(right <= end){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = st ; i <= end ; i++){
         arr[i] = temp[i-st];
    }
}

void printArray(vector<int>&arr , int size){
     for(int i = 0 ; i < size ; i++){
          cout << arr[i] <<" ";
     }
    cout << endl;
}

void mergeSort(vector<int>&arr , int st ,int end){

    if(st >= end) return;

    int mid = st + (end - st)/ 2;
    mergeSort(arr , st , mid);
    mergeSort(arr , mid + 1, end);
    merge(arr , st , mid , end);
    
}

int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    vector<int>arr(size);
    cout <<"Enter the elements of the array"<< endl;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    cout <<"Before Sorted Array"<< endl;
    printArray(arr , size);

    mergeSort(arr , 0 , size - 1);

    cout <<"After Sorted Array"<< endl;
    printArray(arr , size);
    
}