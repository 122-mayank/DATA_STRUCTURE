#include<bits/stdc++.h>
using namespace std;
bool isOdd(int i) {return i % 2;}
int main(){

    // 1.) Searching algorithm

    // // a) find function -> used to find the first occurrence of element
    //      vector<int>v = { 1, 2 , 3 , 4, 5};
    //      sort(v.begin() , v.end());

    //      auto it = find(v.begin() , v.end() , 4);

    //      //print index using the { distance() } -> it calculates the index of found element in
    //     // sorted vector
    //      cout << distance(v.begin() , it);

    // int arr[5] = {1, 3, 6, 2, 9};

    // // Search an element 6
    // auto it = find(arr, arr + 5, 6);

	// // Print index
    // cout << distance(arr, it);
    // return 0;


    // // b) find_if(v.begin() , v.end() ,  a function that returns boolean)
       

    //    vector<int>v2{20 , 30 , 80 , 99 , 50};

    //    vector<int>::iterator it;

    //    it = find_if(v2.begin() , v2.end() , isOdd);

    //    cout << "The first odd value is " << *it << '\n';

    // c) find_if_not(v.begin() , v.end() , isOdd);

    //  vector<int> vec{ 10, 25, 40, 55 };

    // // Iterator to store the position of element found
    // vector<int>::iterator it;

    // // std::find_if_not
    // it = find_if_not(vec.begin(), vec.end(), IsOdd);

    // cout << "The first non-odd(or even) value is " << *it
    //      << '\n';


    //d ) binary_search function used to search the element in sorted array
    vector<int>v= { 1, 2 , 3 , 4, 5 ,6, 8, 9, 11};

    int target = 8;

    if(binary_search(v.begin() , v.end(), target)){
         cout << target <<" found ";
    }
    else{
        cout <<"Not found !!";
    }


}