#include<bits/stdc++.h>
using namespace std;


int kthSmallest(vector<int>arr , int size , int k){

    priority_queue<int> pq;
    int r = arr.size() - 1;

    for( int i = 0 ; i < k ; i++){
        pq.push(arr[i]);
    }

    //process for rest elements

    for( int i = k ; i <= r ; i++){

        int element = pq.top();
        if( element > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans ;
}

int main(){

    int size;
    cout <<"Enter the size of the array: "<< endl;
    cin >> size;

    vector<int> arr(size);

    cout <<"Insert the array elements: "<<endl;
    for(int i = 0 ; i  < size ; i++){
        cin >> arr[i];
    }
    
    int k ;
    cout <<"Enter the value of k : "<<endl;
    cin >> k;

    int ans = kthSmallest(arr , size , k);
    cout <<"The value of " << k <<" smallest element is: "<< ans << endl;



}