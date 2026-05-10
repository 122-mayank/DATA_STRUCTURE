#include<iostream>
using namespace std;

class Heap{

    public:
    int arr[100];
    int size = 0;

    void insert(int val){
          
        size = size + 1;
        int index = size;
        arr[index] = val;


        while( index > 1){
              int parent = index / 2;

              if( arr[parent] < arr[index]){
                swap( arr[index] , arr[parent]);
                index = parent;
              }

              else{
                return ;
              }

        }
    }

    void print(){

        for( int i = 1 ; i <= size ; i++){
            cout << arr[i] <<" ";
        }

        cout << endl;

    }

    void deleteFromHeap(){

        if( size == 0){
            cout << "Nothing to delete "<< endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //take rootnode to its cuurent position
       int i = 1;
        while(i <= size) {
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = i;

    if(leftIndex <= size && arr[leftIndex] > arr[largest]) {
        largest = leftIndex;
    }
    if(rightIndex <= size && arr[rightIndex] > arr[largest]) {
        largest = rightIndex;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        i = largest;
    } else {
        return;
    }
}


    }

};

void heapify(int arr[] , int n , int i ){

        int largest = i;
        int left = 2 * i;
        int right =2 * i + 1;

        if( left <= n && arr[largest] < arr[left] ){
            largest = left;
        }

       if( right <= n && arr[largest] < arr[right] ){
            largest = right;
       }

       if(largest != i){
            swap(arr[largest] , arr[i]);
            heapify( arr , n, largest);
       }

}



void sort(int arr[] , int n){

    int size = n;
    while( size  > 1){

        swap(arr[size] , arr[1]);
        size--;

        heapify(arr , size , 1);

    }
 }   

int main(){

    Heap h;
    h.insert(23);
    h.insert(12);
    h.insert(11);
    h.insert(76);
    h.insert(34);
    h.insert(80);

    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[8] = { -1 , 23 , 45 , 67 , 48 , 12 , 14 , 32};
    int n = 7;

    for( int i = n / 2 ; i > 0 ; i--){
         heapify(arr , n , i);
    }

    cout <<"Prinitng the array now: "<< endl;
    for( int i = 1 ; i <= n; i++){
        cout << arr[i] << " ";
    }

    sort(arr , n );
    cout << endl;
    
    cout <<"Prinitng the sorted array: "<< endl;
    for( int i = 1 ; i <= n; i++){
        cout << arr[i] << " ";
    }


}
