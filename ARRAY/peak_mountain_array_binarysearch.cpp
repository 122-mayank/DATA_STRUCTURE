#include<iostream>
using namespace std;


int mountainArray(int* arr , int size){
           
    int s = 0;
    int e = size - 1;
    while( s < e){

           int mid = s + (e -s)/2;
           if( arr[mid] < arr[mid+1]){
                s = mid+1;
           }
           else{
            e = mid;
           }

    }
return s;

}

int main(){

int size ;
cout<<"Enter the szie: "<<endl;
cin >> size;

int *arr = new int[size];

cout <<"Insert the elements"<<endl;
for( int i = 0 ; i < size ; i++){
    cin >> arr[i];
}

int ans = mountainArray(arr , size);
cout <<"The peak element is: "<< arr[ans] <<endl;


}