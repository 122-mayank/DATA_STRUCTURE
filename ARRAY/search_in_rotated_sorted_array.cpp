#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>&arr , int size){

      int s = 0;
      int e = arr.size() - 1;

      while(s < e){ 

           int mid = s + (e - s) / 2;

           if(arr[mid] >= arr[0]){
                s = mid + 1;
           }
           else{
            e = mid;
           }

      }

      return s;

}

int binarySearch(vector<int>& nums, int s, int e, int target) {

        int mid = s + (e - s) / 2;

        while (s <= e) {

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }

        return -1;
    }

int main(){

    int size;
    cout <<"Enter the size"<< endl;
    cin >> size;

    vector<int>arr(size);

    cout <<"Enter the elements of the array "<< endl;
    for(int i = 0 ; i < size ; i++){
         cin >> arr[i];
    }

    //get the pivot
    int pivot = getPivot(arr , size);
    int ans = -1;
    if(target >= arr[pivot] && target<= arr[size-1]){
        ans = binarySearch(arr, pivot , size - 1, target);
    }
    else{
       ans = binarySearch(arr, 0 , pivot - 1, target);
    }

}