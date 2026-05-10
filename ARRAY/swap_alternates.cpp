#include<iostream>
using namespace std;

int main(){

    int size;
    cout <<"Enter the size: "<<endl;
    cin >> size;
    
    int *arr = new int[size];
    cout<<"Insert elemments: "<<endl;
    for( int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }


    for( int i= 0 ; i < size ; i += 2){
         
        if( i + 1 < size){
            swap(arr[i] , arr[i+1]);
        }

    }

    for( int i = 0 ; i < size ; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}