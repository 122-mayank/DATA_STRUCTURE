#include<iostream>
using namespace std;

void insertionSort(int *arr , int size){
            
    int i ,j;
    for( i = 0 ; i < size ; i++){
        int temp = arr[i];
        for(  j = i - 1; j >=0 ; j--){
            
               if( temp < arr[j] ){
                arr[j+1] = arr[j];
               }
               else{
                break;
               }

        }
        arr[j+1] = temp;
    }


}

void print(int *arr , int size){
        
        for( int i = 0; i < size ; i++){
            cout << arr[i] <<" ";
        }

        cout << endl;

}


int main(){

 int size;
 cout <<"Enter the size : "<<endl;
 cin >> size;

 int *arr = new int[size];
 cout<<"Insert the elements of array: "<<endl;
 for(int i = 0 ; i < size ; i++){
    cin >> arr[i];
 }

 insertionSort(arr , size);
 print(arr , size);


}