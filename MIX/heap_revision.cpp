#include<bits/stdc++.h>
using namespace std;

class MaxHeap{

public:
    vector<int> heap;

    MaxHeap(vector<int>& arr){
        heap = arr;
        buildHeap();
    }

    // Build max heap from array
    void buildHeap(){
        int n = heap.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(i);
        }
    }

    // Heapify down (0-index based)
    void heapifyDown(int index){
        int n = heap.size();

        while(true){
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;

            if(left < n && heap[left] > heap[largest])
                largest = left;

            if(right < n && heap[right] > heap[largest])
                largest = right;

            if(largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

    // 🌟 DELETE ROOT FUNCTION (for max heap)
    void deleteRoot(){
        int n = heap.size();
        if(n == 0){
            cout << "Heap is empty!" << endl;
            return;
        }

        // Step 1: Replace root with last element
        heap[0] = heap[n - 1];

        // Step 2: Remove last element
        heap.pop_back();

        // Step 3: Heapify Down from root
        heapifyDown(0);
    }

    // Print heap
    void printHeap(){
        for(int x : heap){
            cout << x << " ";
        }
        cout << endl;
    }

};


int main(){

    int size;
    cout << "Enter the size : ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    MaxHeap h(arr);

    cout << "Max Heap: " << endl;
    h.printHeap();

    // 🔥 Delete root example
    cout << "Deleting root..." << endl;
    h.deleteRoot();

    cout << "After deletion: " << endl;
    h.printHeap();

}
































    //    Ist approach ->   Build Heap from array ->  Heapify up alfo takes the O(n logn) time
//  #include<bits/stdc++.h>
//  using namespace std;

//  class MaxHeap{

//     public:
//     vector<int>heap;
//     int size;

//     MaxHeap(int size){
//          this -> size = size;
//          (size);
//     }

//     void insert(int value){
//         heap.push_back(value);
//         heapifyup(heap.size() - 1);
//     }




//  void heapifyup(int index){

//     if(index == 0){
//         return;
//     }


//     int parent = (index - 1) / 2;
//     if(heap[parent] < heap[index]){
//             swap(heap[parent] , heap[index]);
//             heapifyup(parent);
//     }
//  }

// void print(){

//     for(int num : heap){

//          cout << num <<" ";


//     }
//     cout << endl;

// }

// };

//  int main(){


//     int size;
//     cout <<"Enter the size of max heap: "<<endl;
//     cin >> size;

//     MaxHeap h(size);

//     int data;
//     for(int i = 0 ;i< size ; i++)
// {
//      cin >> data;
//      h.insert(data);
// }

// cout <<"Max Heap: "<< endl;
// h.print();

//  }


//  2nd Approach -> Build Heap from array -> Heapify down takes O(n)
// #include <bits/stdc++.h>
// using namespace std;

// class MaxHeap {
// public:
//     vector<int> heap;

//     // Constructor when array already exists
//     MaxHeap(vector<int> &arr) {
//         heap = arr;
//         buildHeap();
//     }

//     // ---------------- HEAPIFY DOWN ---------------- //
//     void heapifyDown(int index) {
//         int n = heap.size();

//         while (true) {
//             int left = 2 * index + 1;
//             int right = 2 * index + 2;
//             int largest = index;

//             // check left child
//             if (left < n && heap[left] > heap[largest]) {
//                 largest = left;
//             }

//             // check right child
//             if (right < n && heap[right] > heap[largest]) {
//                 largest = right;
//             }

//             // if parent is already largest → stop
//             if (largest == index) break;

//             // swap and continue going down
//             swap(heap[index], heap[largest]);
//             index = largest;
//         }
//     }


//     // ---------------- BUILD HEAP (O(n)) ---------------- //
//     void buildHeap() {
//         int n = heap.size();

//         // last non-leaf node = (n/2) - 1
//         for (int i = (n / 2) - 1; i >= 0; i--) {
//             heapifyDown(i);
//         }
//     }

//     // Print heap
//     void printHeap() {
//         for (int x : heap) cout << x << " ";
//         cout << endl;
//     }
// };


// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter array elements: ";
//     for (int i = 0; i < n; i++) cin >> arr[i];

//     MaxHeap h(arr);

//     cout << "Max Heap: ";
//     h.printHeap();

//     return 0;
// }





