#include<iostream>
#include<climits>

using  namespace std;

int main(){

     int f_max = INT_MIN;
     int s_max = INT_MIN;

    int arr[8] = { 45 , 23 , 21 , 89 , 56, 43 , 78 , 12};

    for( int i = 0 ; i < 8 ; i++){

               if( f_max < arr[i]){
                s_max = f_max;
                f_max = arr[i];
               }
               
             if( f_max > arr[i] && s_max < arr[i]){
                s_max = arr[i];
             } 
    }

    cout <<"Second Maximum value in the arary: "<<s_max<<endl;



}