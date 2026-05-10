#include<iostream>
#include<array>
using namespace std;

int main(){

    int size1 , size2;
    cout <<"Enter the size of 1st array: "<<endl;
    cin >> size1;

    cout <<"Enter the size of the 2nd array: "<<endl;
    cin >> size2;
    
    int *arr1 = new int[size1];
    cout <<"Enter the 1st array elements: "<<endl;
    for( int i = 0 ; i < size1 ; i++){
        cin >> arr1[i];
    }
    
    int*arr2 = new int[size2];
    cout <<"Enter the 2nd array elements: "<<endl;
    for( int i = 0 ; i < size2 ; i++){
          cin >> arr2[i];
    }

    int* merge = new int[size1 + size2];
    int i = 0 , j = 0 , k = 0;

    while( i < size1 && j < size2){

        if(arr1[i] < arr2[j]){
               merge[k++] = arr1[i++];
        }

        else{
            merge[k++] = arr2[j++];
        }

    }


    while( i < size1){
        merge[k++] = arr1[i++];
    }

    while( j < size2){
        merge[k++] = arr2[j++];
    }

    // Printing merge Array
    cout <<"The Merge sorted Array is: "<<endl;

    for( int i = 0 ; i < size1 + size2 ; i++){

        cout <<merge[i] <<" ";
         
    }


}