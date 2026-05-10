#include<iostream>
using namespace std;


int main(){

int size;
cout <<"Enter the size: "<<endl;
cin >> size;

int*arr = new int[size];

cout <<"Enter the array elements: "<<endl;
for( int i = 0 ; i < size ; i++){
    cin >>arr[i];
}

// logic to move zeroes at right position
int  i = 0 ;
for( int j = 0 ; j < size ; j++){
     
    if( arr[j] != 0){
        swap(arr[i] , arr[j]);
        i++;
    }
}

// printing the array
cout <<"Move zeroes to last position: "<<endl;
for( int i = 0 ; i < size ; i++){
    cout << arr[i] <<" ";
}


}