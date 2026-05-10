#include<iostream>
using namespace std;


int main(){

   int size ;
   cout <<"Enter the size: "<<endl;
   cin >> size;

   int *arr = new int[size];

   cout<<"Insert Elements: "<<endl;
   for( int i = 0 ; i < size ;i++){
    cin >> arr[i];
   }

   



}