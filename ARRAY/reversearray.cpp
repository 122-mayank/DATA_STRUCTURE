#include<iostream>
using namespace std;

int main(){

int arr[5] = { 90 , 80 , 70 , 60 , 50};
int size = sizeof(arr) / sizeof(arr[0]);

int st = 0;
int end =  size - 1;

while( st <= end){

    swap(arr[st] , arr[end]);
    st++;
    end--;
    
}

cout <<"Reverse the array: "<<endl;
for( int i = 0 ; i < size ; i++){
    cout << arr[i] <<" ";
}
cout <<endl;

}