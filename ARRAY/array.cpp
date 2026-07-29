// Question -> Find the duplicate number

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr , int st , int end , int target){

     if(st > end){
          return -1;
     }

     int mid = st + (end - st) / 2;

     if(arr[mid] == target){
          return mid;
     }

    else if(arr[mid] > target){
         return binarySearch(arr, st , mid -1 , target);
     }
     else{
          return binarySearch(arr , mid + 1, end, target);
     }

}

int main(){

     int size;
     cout <<"Enter the size"<< endl;
     cin >> size;

     vector<int>arr(size);
     cout <<"Enter the array elements"<< endl;
     for(int i = 0 ; i < size ; i++){
          cin >> arr[i];
     }

     int target;
     cout <<"Enter the target"<< endl;
     cin >> target;
     int ans = binarySearch(arr, 0 , size - 1 , target);
     if(ans != -1){
           cout <<"Element is found!!"<< endl;
     }
     else{
          cout <<"Element is not found !!"<< endl;
     }

}













// Question -> Find first and last position of element in sorted array

// #include<bits/stdc++.h>
// using namespace std;

// int lastOccurrence(vector<int>&arr , int target){

//      int st = 0;
//      int end = arr.size() - 1;

//      int ans = -1;


//      while(st <= end){

//           int mid = st + (end - st) / 2;

//           if(arr[mid] == target){
//                 ans = mid;
//                 st = mid + 1;
//           }
//           else if(arr[mid] > target){
//                end = mid - 1;
//           }
//           else{
//                 st = mid + 1;
//           }

//      }

//      return ans;

// }

// int firstOccurrence(vector<int>&arr , int target){

//      int st = 0;
//      int end = arr.size() - 1;

//      int ans = -1;

//      while(st <= end){

//           int mid = st + (end - st )/ 2;

//           if(arr[mid] == target){
//                ans = mid;
//                end = mid - 1;
//           }
//           else if(arr[mid] > target){
//                 end = mid - 1;
//           }
//           else{
//                st = mid + 1;
//           }

//      }

//      return ans;

// }

// int main(){
     
//      int size;
//      cout <<"Enter the size"<< endl;
//      cin >> size;

//      vector<int>arr(size);
//      cout <<"Enter the elements of the array"<< endl;
//      for(int i = 0 ; i < size ; i++){
//            cin >> arr[i];
//      }

//      int target;
//      cout <<"Enter the target"<< endl;
//      cin >> target;

//      int f_occur = firstOccurrence(arr , target);
//      int l_occur = lastOccurrence(arr , target);

//      cout <<"First and last occurrence of the " << target << " is "<< f_occur <<" , "<< l_occur;

// }


// Question -> Search in rotated sorted array

// #include<bits/stdc++.h>
// using namespace std;

// int binarySearch(vector<int>&arr , int st , int end , int target){

//      while(st <= end){

//           int mid = st + ( end - st) / 2;

//           if(arr[mid] == target){
//               return mid;
//           }
//           else if(arr[mid] > target){
//                end  = mid - 1;
//           }
//           else{
//                st = mid + 1;
//           }

//      }

//      return -1;


// }


// int findPivot(vector<int>&arr){

//      int st = 0;
//      int end = arr.size() - 1;

//      while( st < end){

//           int mid = st + (end - st) / 2;

//           if(arr[mid] >= arr[0]){
//                 st = mid + 1;
//           }
//           else{
//                end = mid;
//           }
//      }

//      return st;
// }

// int main(){

//      int size;
//      cout <<"Enter the size"<< endl;
//      cin >> size;

//      vector<int>arr(size);
//      cout <<"Enter the elements of the array"<< endl;
//      for(int i = 0 ; i < size ; i++){
//           cin >> arr[i];
//      }

//      int target;
//      cout <<"Enter the target value "<< endl;
//      cin >> target;

//      int pivot = findPivot(arr);
//      int idx = -1;

//      if(target >= pivot && target <= arr[arr.size()-1]){
//            idx = binarySearch(arr , pivot, arr.size() - 1 , target);
//      }
//      else{
//           idx = binarySearch(arr, 0, pivot - 1, target);
//      }

//      if(idx != -1){
//           cout <<"Element at found at " << idx << endl;
//      }
//      else{
//           cout <<"Element not found !!"<< endl;
//      }

// }



//Question -> Find the search insert position

// #include<bits/stdc++.h>
// using namespace std;

// int getPosition(vector<int>&arr , int target){

//      int st = 0;
//      int end = arr.size() - 1;
     
//      while(st <= end){

//           int mid = st + (end - st) / 2;

//           if(arr[mid] == target){
//                return mid;
//           }
//           else if(arr[mid] > target){
//                end = mid -1 ;
//           }
//           else{
//                st = mid + 1;
//           }

//      }
    
//      return st;

// }

// int main(){

//      int size;
//      cout <<"Enter the size of the array "<< endl;
//      cin >> size;

//      vector<int>arr(size);

//      cout <<"Enter the elements of the array "<< endl;
//      for(int i = 0 ; i < size ; i++){
//           cin >> arr[i];
//      }

//      int target;
//      cout <<"Enter the target element"<< endl;
//      cin >> target;

//      int idx = getPosition(arr, target);

//      cout <<"Index "<< idx <<" at element found or may be found "<< endl;



// }



// // Binary Search  ----> O(log n)

// #include<bits/stdc++.h>
// using namespace std;

// int binarySearch(vector<int>&arr , int target){

//      int i = 0;
//      int j = arr.size() - 1;

//      while( i <= j){

//           int mid = i + ( j - i )/ 2;

//           if(arr[i] == target){
//                 return mid;
//           }

//           else if( arr[i] > target){
//                j = mid - 1;
//           }
//           else{
//                i = mid + 1;
//           }

//      }

//      return -1;
     
     
// }

// int main(){

//      int size;
//      cout <<"Enter the size "<< endl;
//      cin >> size;


//      //make the array
//      vector<int>arr(size);

//      cout <<"Enter the elements of the array "<< endl;
//      for(int i = 0 ; i < size ; i++){
//           cin >> arr[i];
//      }

//      int target;
//      cout <<"Enter the target element"<< endl;
//      cin >> target;

//      int idx = binarySearch(arr, target);

//      if(idx != -1){
//           cout <<"Element found at index "<< idx << endl;
//      }
//      else{
//           cout <<"Element is not found"<< endl;
//      }

// }