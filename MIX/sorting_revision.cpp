//Bubble Sort
#include<bits/stdc++.h>
using namespace std;

int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    

}
















// //Selection Sort 

// #include<bits/stdc++.h>
// using namespace std;


// void selectionSort(vector<int>&arr , int size){

//     for(int i = 0 ; i < arr.size() - 1 ; i++){

//         int min_index = i;

//         for(int j = i + 1 ; j < arr.size() ; j++){

//             if(arr[min_index] > arr[j]){
//                  min_index = j;
//             }

//         }

//         swap(arr[min_index] , arr[i]);

//     }
//     cout << endl;

// }

// void print(vector<int>&arr , int size){

//     for(int i = 0 ; i < arr.size() ; i++){
//          cout << arr[i] <<" ";
//     }
//     cout << endl;
// }

// int main(){

//     int size;
//     cout <<"Enter the size "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the array elements"<< endl;
//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//     }

//     cout <<"Before Sorted Array"<< endl;
//     print(arr , size);

//     selectionSort(arr , size);

//     cout <<"After Sorted Array "<< endl;
//     print(arr , size);
// }