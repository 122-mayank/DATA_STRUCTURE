
// Day - 5 Recursion Practice

//  Q - 5 Linear Search using Recursion

// #include<bits/stdc++.h>
// using namespace std;


// int linearSearch(vector<int>&arr , int idx , int ele){

//     if(idx >= arr.size()){
//              return -1;
//     }

//     if(arr[idx] == ele){
//         return idx;
//     }

//     return linearSearch(arr , idx + 1, ele);

// }

// int main(){

//     int size;
//     cout <<"Enter the size of the array: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the array elements: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }

//     int ele;
//     cout <<"Enter the search element: "<< endl;
//     cin >> ele;


//     int ans = linearSearch(arr , 0 , ele);

//     if(ans == -1){
//         cout <<"Element is not found!!"<< endl;
//     }

//     else{
//         cout <<"Element "<< ele <<" is found at index "<< ans << endl;
//     }

// }






//  Q - 4 Count the occurrences of the element

// #include<bits/stdc++.h>
// using namespace std;

// int countOccurrences(vector<int>& arr, int ele, int i){

//     if(i == arr.size()) return 0;

//     int countHere = (arr[i] == ele) ? 1 : 0;

//     return countHere + countOccurrences(arr, ele, i+1);

// }

// int main(){

//     int n;
//     cout <<"Enter the size: ";
//     cin >> n;

//     cout <<"Enter the array elements: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }

//     int ans = countOccurrences(arr , i);
//     cout <<"Answer is: "<< ans << endl;

// }


//  Q - 3 Find the last occurrence of the array

// #include<bits/stdc++.h>
// using namespace std;

// int lastOccurrence(vector<int>& arr, int ele, int i){

//     if(i == arr.size()) return -1;

//     int indexFromRight = lastOccurrence(arr, ele, i+1);

//     if(indexFromRight != -1) return indexFromRight;

//     if(arr[i] == ele) return i;

//     return -1;

// }


// int main(){

//     int size;
//     cout <<"Enter the size: "<< endl;
//     cin >> size;

//     cout <<"Enter the elements of the array: "<< endl;
//     vector<int>arr(size);

//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//     }

//     int ele;
//     cout <<"Enter the element: "<< endl;
//     cin >> ele;

//     int ans  = lastOccurrence(arr , ele , 0 );
//     cout <<"Answer is : "<< ans << endl;


// }






//  Q - 2 Find first occurrence of array

// #include<bits/stdc++.h>
// using namespace std;

// int findOccurrence(vector<int>&arr , int i , int ele){

//     if( i == arr.size()){
//         return -1;
//     }

//     if(ele == arr[i]){
//         return i;
//     }


//    return findOccurrence(arr , i +1  , ele);

// }


// int main(){

//     int size;
//     cout <<"Enter the size: "<< endl;
//     cin >> size;

//     vector<int>arr(size);
//     cout <<"Enter the elements: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//     }

//     int ele;
//     cout <<"Enter the element: "<< endl;
//     cin >> ele;

//     int ans = findOccurrence(arr , 0 , ele);
//     cout <<"Answer is: "<< ans << endl;

// }




//  Q - 1 Find the sum of the array

// #include<bits/stdc++.h>
// using namespace std;

// int sumArray(vector<int>&arr , int i){

//     if(i >= arr.size()){
//         return 0;
//     }

//     return arr[i] + sumArray(arr , i + 1);

// }



// int main(){

//     int size;
//     cout << "Enter the size : ";
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the array elements: "<< endl;

//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }

//     int ans = sumArray(arr , 0);
//     cout <<"Sum of the array: "<< ans << endl;

// }











//  Day - 4 Recusrsion Practice

// Q - 1 Print array elements

// #include<bits/stdc++.h>
// using namespace std;

// void print(vector<int>&arr , int i){

//     if( i == arr.size()){
//         return;
//     }


//     cout << arr[i] <<" ";
//     print(arr , ++i);
// }

// int main(){

//     int size;
//     cout <<"Enter the size: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the elements of the array: "<< endl;

//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//     }

//     print(arr , 0 );
// }

//  Q - 2 Print array in reverse

// #include<bits/stdc++.h>
// using namespace std;

// void print(vector<int>&arr , int i){

//     if( i < 0){
//         return;
//     }


//     cout << arr[i] <<" ";
//     print(arr , i - 1);
// }

// int main(){

//     int size;
//     cout <<"Enter the size: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the elements of the array: "<< endl;

//     for(int i = 0 ; i < size ; i++){
//         cin >> arr[i];
//     }

//     print(arr , size -1 );
// }

//  Q - 3 Find the maxiumum element in the array

// #include<bits/stdc++.h>
// using namespace std;

// int maximumNum(vector<int>&arr , int i){

// if(arr.size() == i){
//     return INT_MIN;
// }

// return max(arr[i] , maximumNum(arr , i + 1));


// }

// int main(){

//     int size;
//     cout <<"Enter the size "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//      cout <<"Enter the array of elements: "<< endl;
//     for(int i = 0; i < size ; i++){
//         cin >> arr[i];
//     }

//     int ans = maximumNum(arr  , 0);

//     cout <<"Maximum number : "<< ans << endl;


// }

//  Q - 4 Find the minimum elements

//  #include<bits/stdc++.h>
// using namespace std;

// int minimumNum(vector<int>&arr , int i){

// if(arr.size() == i){
//     return INT_MAX;
// }

// return min(arr[i] , minimumNum(arr , i + 1));

// }

// int main(){

//     int size;
//     cout <<"Enter the size "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//      cout <<"Enter the array of elements: "<< endl;
//     for(int i = 0; i < size ; i++){
//         cin >> arr[i];
//     }

//     int ans = minimumNum(arr  , 0);

//     cout <<"Minimum number : "<< ans << endl;


// }

//  Q - 5 Check if array is sorted

// #include<bits/stdc++.h>
// using namespace std;

// bool checkSorted(vector<int>& arr, int i){
//     if(i == arr.size()-1) return true;

//     if(arr[i] > arr[i+1]) return false;

//     return checkSorted(arr, i+1);
// }

// int main(){

//     int size ;
//     cout <<"Enter size of the array: "<< endl;
//     cin >> size;

//     vector<int>arr(size);

//     cout <<"Enter the array elements: "<< endl;
//     for(int i = 0 ; i < size ; i++){
//          cin >> arr[i];
//     }

//     bool ans = checkSorted(arr , 0);

//     if(ans){
//         cout <<"Sorted array"<< endl;
//     }
//     else{
//         cout <<"Not Sorted array"<< endl;
//     }

// }




// Day - 3 Recursion Practice


//  Q - 1 Print the nth fibonacci number

// #include<bits/stdc++.h>
// using namespace std;

// int fib(int n){

//     if(n == 2 || n == 1){
//         return n;
//     }

//     return fib(n-1) + fib(n-2);
// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;


//     int ans = fib(n);

//     cout << "The Nth Fibonacci number is: "<< ans << endl;

// }

//  Q - 2 Print Fibonacci Series till N

// #include<bits/stdc++.h>
// using namespace std;

// int fib(int i){

//     if( i == 2 || i == 1){
//         return i;
//     }

//     return fib(i-1) + fib(i-2);

// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     cout <<"Fibonacci Series till N: "<< endl;
//     for(int i = 1 ; i <= n ; i++){
//          int ans = fib(i);
//          cout << ans << " ";
//     }

//     cout << endl;

// }

//  Q - 3 Reverse a number

// #include<bits/stdc++.h>
// using namespace std;

// int reverse(int n, int ans = 0){
//     if(n == 0) return ans;
//     return reverse(n/10, ans*10 + n%10);
// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int count = 0;

//     reverse(n , count);
//     cout <<"Reverse of the number is : "<< count << endl;
// }

//  Q - 4 Check if a number is palindrome

// #include<bits/stdc++.h>
// using namespace std;

// void palindrome(int  n , int&ans){


//     if( n == 0){
//         return;
//     }

//    ans = ans * 10 + ( n % 10);
//    palindrome(n / 10  , ans);

// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int ans = 0;
//     palindrome(n , ans);

//     if(ans == n){
//         cout <<"Number is Palindrome"<< endl;
//     }

//     else{
//         cout <<"Number is not Palindrome"<< endl;
// }

// }

//  Q - 5 Find GCD using recursion

// #include<bits/stdc++.h>
// using namespace std;

// int gcd(int a, int b){

//     if(b == 0) return a;
//     return gcd(b, a % b);

// }

// int main(){

//     int n , m;
//     cout <<"Enter the number( m , n ): "<< endl;
//     cin >> m >> n;

//     int ans = gcd(m , n);

//     cout <<"Gcd of the m and n is " << ans << endl;

// }




//  Day - 2
// Q - 1 FInd the factorial of the number

// #include<bits/stdc++.h>
// using namespace std;

// int fact(int n){

//     if( n == 0 || n == 1){
//         return 1;
//     }

//     return n * fact(n-1);

// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int ans = fact(n);

//     cout <<"Factorial of number is: "<< ans << endl;

// }


// Q - 2 Find the sum of digits of a number


// #include<bits/stdc++.h>
// using namespace std;

// int sumDigits(int n) {
//     if (n == 0) return 0;
//     return (n % 10) + sumDigits(n / 10);
// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int ans = sumDigits(n , 0);

//     cout <<"Sum of digits " << ans << endl;


// }


// Q - 3 Find the power x to n

// #include<bits/stdc++.h>
// using namespace std;

// int power(int x , int n){

//     if( n == 1){
//         return x;
//     }

//     return x * power(x , n -1);

// }

// int main(){

//     int x , n;
//     cout <<"Enter the number(x): ";
//     cin >> x;

//     cout <<"Enter the power(n): ";
//     cin >> n;

//     int ans = power(x , n);
//     cout << "Power of x : " << ans << endl;

// }

//  Q - 4 Find the product of digits

// #include<bits/stdc++.h>
// using namespace std;

// int productDigits(int n) {
//     if (n == 0) return 1;
//     return (n % 10) * productDigits(n / 10);
// }


// int main(){


//     int n;
//     cout <<"Enter the number: ";
//     cin >> n;

//     int ans = productDigits(n );
//     cout <<"Answer is : "<< ans << endl;
// }

// Q - 5 Find the count number of digits

// #include<bits/stdc++.h>
// using namespace std;

// void countDigits(int n , int&count){

//     if(n == 0){
//         return;
//     }

//     count = count  + 1;
//     countDigits(n / 10 , count);
// }

// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int count = 0;
//     countDigits(n , count);

//     cout <<"Answer: "<< count << endl;

// }






// Day - 1 : Practice the recursion questions

//  Q - 1: Print Numbers from 1 to N

// #include<bits/stdc++.h>
// using namespace std;

// void print(int i , int n ){

//      if( i > n){
//         return;
//      }

//      cout << i <<" ";
//      print(++i, n);
// }
// int main(){

//     int n;
//     cout <<"Enter the numbers: "<< endl;
//     cin >> n;

//     print(1 , n);

// }


// Q - 2 : Print Numbers from N to 1

// #include<bits/stdc++.h>
// using namespace std;

// void print(int n ){

//      if( n == 0){
//         return;
//      }

//      cout << n <<" ";
//      print (n - 1);
// }
// int main(){

//     int n;
//     cout <<"Enter the numbers: "<< endl;
//     cin >> n;

//     print(n);

// }

//  Q - 3 Print Hello "N" Times

// #include<bits/stdc++.h>
// using namespace std;

// void print(int n){

//     if( n == 0){
//         return ;
//     }

//     cout <<"Hello"<< endl;
//     print(n-1);
// }

// int main(){

//      int n;
//      cout <<"Enter the n: ";
//      cin >> n;

//      print(n);
// }


// Q - 4 Print even numbers from all 1 to N

// #include<bits/stdc++.h>
// using namespace std;

// void print(int i , int n){

//     if( i > n){
//         return;
//     }

//     if( i % 2 == 0){
//         cout << i << endl;
//     }

//     print( i + 1, n);


// }

// int main(){

//     int n ;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     print(1 , n);

// }


// Q - 5 Print Sum of first N natural numbers

// #include<bits/stdc++.h>
// using namespace std;

// int sum(int n){

//     if(n == 0){
//         return 0;
//     }

//     return n + sum(n-1);

// }


// int main(){

//     int n;
//     cout <<"Enter the number: "<< endl;
//     cin >> n;

//     int ans = sum(n);
//     cout << ans << endl;
// }