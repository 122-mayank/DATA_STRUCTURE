#include<iostream>
using namespace std;

//Morre's Voting Algorithm
int majorityElement(int *arr , int size){

       int count = 0;
       int candidate = -1;

       for( int i = 0 ; i < size ; i++){
                   
                if( count == 0){
                    candidate = arr[i];
                    count = 1;
                }

                else if( arr[i] == candidate){
                    count++;
                }
                else{
                    count --;
                }
         
       }
    count = 0;
    for( int i = 0 ; i < size ; i++){
            
         if( arr[i] == candidate){
            count++;
         }

    }

    if( count > size / 2){
         return candidate;
    }

    return -1;

}

int main(){

    int size;
    cout <<"Enter the size of the array: "<<endl;
    cin >> size;

    int* arr = new int[size];
    cout <<"Insert elements: "<<endl;
    for( int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }


    int ans = majorityElement(arr , size);
    if( ans != -1){
        cout <<"The majority elements is: "<< ans <<endl;
    }

    else{
        cout <<"Majority element does not exist"<<endl;
    }
     
}