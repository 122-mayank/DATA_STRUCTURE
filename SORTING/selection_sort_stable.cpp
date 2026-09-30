#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&arr , int size){

    for(int i = 0 ; i < size ; i++){
        cout << arr[i] <<" ";
    }
}

void selectionSort(vector<int>&arr , int size){

    for(int i = 0 ; i < size - 1 ; i++){

        int min_index = i;

        for(int j = i + 1 ; j < size ; j++){
             if(arr[j] < arr[min_index]){
                min_index = j;
             }
        }

        int key = arr[min_index];

        while(min_index > i){
            arr[min_index] = arr[min_index - 1];
            min_index--;
        }
        arr[i] = key;
    }

}

int main(){

    int size;
    cout <<"Enter the size of array"<< endl;
    cin >> size;

    vector<int>arr(size);
    cout <<"Enter the elements of array"<< endl;
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }

    cout <<"Before Sorted Array"<< endl;
    print(arr , size);

    selectionSort(arr , size);

    cout <<"After Sorted Array"<< endl;
    print(arr , size);

}