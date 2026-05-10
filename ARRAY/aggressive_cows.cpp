#include<iostream>
using namespace std;


bool isPossible(int *arr , int mid , int k , int size){

    int cowCount = 1;
    int lastPos= arr[0];
    for( int i = 0 ; i < size ; i++ ){
            
        if(arr[i] - lastPos >= mid){
            cowCount++;
            if( cowCount == k ){
                return true;
            }
            lastPos = arr[i];

        }

    }

return false;

}

int agressiveCows(int*arr , int size , int k){

        int st = 0;
        int maxi = -1;
        for( int i  = 0 ; i < size ; i++){
            if(maxi < arr[i]){
                    maxi = arr[i];
            }
        }
        int ans;
        int end = maxi;
        int mid = st + (end - st)/2;
        while( st <= end ){
             
             if(isPossible(arr , mid , k , size)){
                ans = mid;
                st = mid +1;
             }
             else{
                end = mid - 1;
             }
             mid = st + (end - st)/2;
                  
        }
         return ans;

}
   
int main(){

    int size;
    cout <<"Enter the size: "<<endl;
    cin >> size;
     
    int*arr = new int[size];
    cout<<"Enter the elements in sorted arary: "<<endl;
    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }
    int k;
    cout <<"Enter the aggressive cows: "<<endl;
    cin >>k;
    int ans = agressiveCows(arr , size,k);
    cout << "Answer is: "<<ans<<endl;




}