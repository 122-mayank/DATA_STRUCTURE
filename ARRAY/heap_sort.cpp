#include<bits/stdc++.h>
using namespace std;

void heapifyDown(int index, vector<int>&arr , int n){

    //  int n = arr.size();

     while(true){

        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < n &&  arr[largest] < arr[left]){
            largest = left;
        }

        if(right < n && arr[largest] < arr[right]){
             largest = right;
        }

        if(largest == index){
            break;
        }
        swap(arr[largest] , arr[index]);
        index = largest;

     }

}
int main(){

int size;
cout <<"Enter the size: "<< endl;
cin >> size;

vector<int>arr(size);
cout <<"Enter the elements: "<< endl;

for(int i = 0 ; i < size ; i++){
    cin >> arr[i];
}
int n = size;

//heapify down to make the heap
for(int i = n/ 2 -1 ; i>= 0 ; i--){
     heapifyDown( i , arr , n);
}


//logic for heap sort
for(int i = size - 1 ; i > 0 ; i--){
       swap(arr[0] , arr[i]);
       heapifyDown(0 , arr ,i);
}


cout <<"Heap Sort: ";
for(int i = 0 ; i < arr.size() ; i++){
     cout << arr[i] <<" ";
}



}
















































// #include <bits/stdc++.h>
// using namespace std;

// // heapifyDown ensures subtree rooted at i follows MaxHeap property
// void heapifyDown(vector<int>& arr, int size, int i) {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     // check left child exists and is greater than current largest
//     if(left < size && arr[left] > arr[largest]) {
//         largest = left;
//     }

//     // check right child exists and is greater than current largest
//     if(right < size && arr[right] > arr[largest]) {
//         largest = right;
//     }

//     // if largest changed, swap and continue heapifying downward
//     if(largest != i) {
//         swap(arr[i], arr[largest]);
//         heapifyDown(arr, size, largest);
//     }
// }

// void heapSort(vector<int>& arr, int size) {

//     // Step 1: Build max heap
//     for(int i = size / 2 - 1; i >= 0; i--) {
//         heapifyDown(arr, size, i);
//     }

//     // Step 2: Extract max one by one
//     for(int i = size - 1; i > 0; i--) {
//         // place max at the end
//         swap(arr[0], arr[i]);

//         // reduce heap size and heapify root
//         heapifyDown(arr, i, 0);
//     }
// }

// int main() {
//     int size;
//     cout << "Enter the size: ";
//     cin >> size;

//     vector<int> arr(size);

//     cout << "Enter the elements: ";
//     for(int i = 0; i < size; i++) {
//         cin >> arr[i];
//     }

//     heapSort(arr, size);

//     cout << "Sorted array: ";
//     for(int x : arr) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }
