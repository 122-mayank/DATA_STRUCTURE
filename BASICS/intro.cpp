










/*
Count Sort
Time Complexity : O( n * m)
Space Complexity:  O(n + m)
*/

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> countSort(vector<int>&arr , int size){

     
//     int maxval = 0;


//     //find the maximum value

//     for(int i = 0 ; i < size ; i++){
//           maxval = max(maxval , arr[i]);
//     }

//     vector<int>cntArr(maxval + 1, 0);

//     for(int i = 0 ; i < size ; i++){
//          cntArr[arr[i]]++; 
//     }

//     //using the prefix Sum
//     for(int i = 1 ; i <= maxval ; i++){
//            cntArr[i] = cntArr[i] + cntArr[i-1];
//     }


//     vector<int>ans(size);

//     for(int i = size -1 ; i >= 0 ; i--){
        
//          ans[cntArr[arr[i]] - 1] = arr[i];
//          cntArr[arr[i]]--;
//     }

//  return ans;

// }

// int main(){

//     int size;
//     cout <<"Enter the size of the array: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the elements of the array: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }


//     //before sorted array
//     cout <<"Before Sorted Array: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cout << arr[i] <<" ";
//     }

//     vector<int>ans = countSort(arr , size);


//     cout << endl;

//     cout <<"After sorted Array: "<< endl;
//     for(int i = 0 ; i < ans.size() ; i++){
//          cout << ans[i] <<" ";
//     }

//     cout << endl;
    



// }



/*
Radix Sort 
Time Complexity : O(n * (d+b))
Space Complexity : O(n+m)
*/

// #include<bits/stdc++.h>
// using namespace std;


// void countSort(vector<int>&arr , int size , int exp){

//     vector<int>output(size);
//     vector<int>count(10 , 0);

//     for(int i = 0 ; i < size ; i++){
//          count[(arr[i]/exp) % 10]++;
//     }

//     // why prefix Sum is computed

//     for(int i = 1 ; i < 10 ; i++){
//           count[i] += count[i-1];
//     }

//     for(int i = size -1 ; i >= 0 ; i--){
        
//          output[count[(arr[i]/exp) % 10] - 1] = arr[i];
//          count[(arr[i]/exp) % 10]--;

//     }

//     for(int i = 0 ; i < size ; i++){
//          arr[i] = output[i];
//     }

// }

// int getMax(vector<int>&arr){

//     int maxi = INT_MIN;

//     for(int i = 0 ; i < arr.size() ; i++){
        
//          maxi = max(maxi , arr[i]);

//     }

//     return maxi;

// }

// void radixSort(vector<int>&arr , int size){

//     int maxi = getMax(arr);

//     for(int exp = 1 ; maxi / exp > 0 ; exp = exp * 10){
         
//          countSort(arr , size , exp);

//     }

// }

// void print(vector<int>&arr , int size){


//     for(int i = 0 ; i < size ; i++){
//           cout << arr[i]<<" ";
//     }
// }

// int main(){

//     int size;
//     cout <<"Enter the size of the array: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the array elements: "<< endl;
//     for(int i = 0 ; i  < size ; i++){
//          cin >> arr[i];
//      }

//      cout <<"Before Sorted Array: "<< endl;
//      print(arr , size);

//      radixSort(arr , size);

//      cout << endl;
     
//      cout <<"After Sorted Array: "<< endl;
//      print(arr , size);


// }




/*
 Quick Sort --> by choosing the first element as pivot
 Time Complexity : O(n logn)
 Space Complexity : O(n)
*/


// #include<bits/stdc++.h>
// using namespace std;

// int partition(vector<int>&arr , int st , int end){


//     int pivot = arr[end];
//     int i = st - 1;

//     for( int j = st ; j <= end - 1 ; j++){
        
//          if(arr[j] < pivot){
//              i++;
//              swap(arr[i] , arr[j]);
//          }
//     }

//     swap(arr[i+1] , arr[end]);

//     return i+1;

// }
// void quickSort(vector<int>&arr , int st , int end){

//     if(st >= end){
//         return;
//     }
      

//     int pi = partition(arr , st , end);

//     quickSort(arr , st , pi - 1);
//     quickSort(arr, pi + 1 , end);

// }
// void printArray(vector<int>&arr , int size){
    
//      for(int i = 0 ; i < size ; i++){
//          cout << arr[i] <<" ";
//      }

//      cout << endl;

// }

// int main(){

//     int size;
//     cout <<"Enter the size of the array: "<< endl;
//     cin >>size;

//     vector<int>arr(size);

//     cout<<"Enter the array elements: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }

//     cout <<"Before Sorted Array: "<< endl;

//     printArray(arr , size);

//     quickSort(arr , 0 , size - 1);

//     cout << endl;

//     cout <<"After Sorted Array: " << endl;

//     printArray(arr , size);

// }




// Merge Sort

/*
Time Complexity : O(n logn)
Space Complexity: O(n)
*/

// #include<bits/stdc++.h>
// using namespace std;

// void merge(vector<int>&arr , int st ,int mid  , int end){

//     int n1 = mid - st + 1;
//     int n2 = end - mid;

//     vector<int>temp(n1+n2);

//     int i = st;
//     int j = mid + 1;

//     int k = 0;

//     while( i <= mid && j <= end){ 

//            if(arr[i] < arr[j]){

//             temp[k] = arr[i];
//             i++;
//             k++;
            
//            }
//            else{

//             temp[k] = arr[j];
//             j++;
//             k++;
//            }
//     }

//     while( i <=mid){
//           temp[k] = arr[i];
//           k++;
//           i++;
//     }

//     while(j <= end){
//         temp[k] = arr[j];
//         k++;
//         j++;
//     }

    
//     for(int i = 0 ; i < temp.size() ; i++){
//           arr[st+i] = temp[i];
//     }


// }

// void mergeSort(vector<int>&arr , int st , int end){


//     if( st >= end){
//          return;
//     }

//     int mid = st + (end - st) / 2;

//     mergeSort(arr , st , mid);
//     mergeSort(arr , mid + 1 , end);

//     merge(arr , st , mid , end);

// }

// void printArray(vector<int>&arr, int size){

//     for(int i = 0 ; i < size ; i++){
        
//          cout << arr[i] <<" ";

//     }
//     cout << endl;
// }
// int main(){
    
//      int size;
//      cout <<"Enter the size of the array: ";
//      cin >> size;

//      vector<int>arr(size);

//      cout <<"Enter the array elements: ";
//      for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//      }

     

//      cout <<"Before Sorted Array: "<< endl;

//      printArray(arr , size);

//      mergeSort(arr, 0 , size-1);

//      cout << endl;

//      cout <<"After Sorted Array: "<< endl;
//      printArray(arr , size);

// }