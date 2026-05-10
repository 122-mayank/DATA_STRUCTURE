#include<iostream>
using namespace std;

int main(){ 

int size;
cout<<"Enter the size: "<<endl;
cin >> size;

int* arr = new int[size];
cout<<"Insert the elements: "<<endl;
for( int i = 0 ; i < size; i++){
    cin>> arr[i];
}
int ans = 0;
for( int i = 0  ; i <size ; i++){
    ans = ans^ arr[i];
}

for( int i =1 ; i < size ; i++){
    ans = ans^i;
}
 cout <<ans <<endl;

}