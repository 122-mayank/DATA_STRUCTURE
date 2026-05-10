#include<iostream>
#include<climits>
using namespace std;

int main(){

int arr[5] = { 45 , 23 , 21 , 89 , 23};

int max = INT_MIN;

for( int i = 0 ; i < 5 ; i++){

    if( max < arr[i]){
        max = arr[i];
    } 
}

cout <<"Maximum value in the array: "<<max<<endl;


int min = INT_MAX;

for( int i = 0 ; i < 5; i++){

    if( min > arr[i]){
        min = arr[i];
    }
}

cout <<"Minimum value in the arary : "<<min <<endl;



}