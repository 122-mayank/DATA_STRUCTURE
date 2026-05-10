#include<iostream>
using namespace std;

void printArray(int arr[]){

    for( int i = 0 ; i < 15 ; i++){
        cout << arr[i] <<" ";
    }

}

int main(){

int num[15];
cout << num[0] ;
cout << endl <<"Everything is fine "<<endl;

int second[3]={ 3 , 21 , 78};
//accessing an element

cout <<"value at  second index: "<< second[0]<<endl;

// cout << num[20];

int third[15]={9,10};

printArray(third);
              

}