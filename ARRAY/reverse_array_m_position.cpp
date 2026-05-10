#include<iostream>
using namespace std;

int main(){

int size;
cout <<"Enter the size : "<<endl;
cin >> size;

int* arr = new int[size];

cout<<"Enter the array elements: "<<endl;
for( int i = 0 ; i < size ; i++){
    cin >> arr[i];
}

int m;
cout <<"Enter the position: "<<endl;
cin >> m;

// reversing the array by m position
int st = m -1;
int end = size - 1;

while( st <= end){
    swap(arr[st] , arr[end]);
    st++;
    end--;
}

//printing the array elements
for( int i = 0 ; i < size ; i++){
    cout << arr[i] <<" ";
}

}