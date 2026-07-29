#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    //Declares an empty vector
    // vector<int>v1;

    //Declares vector with given size
    // and fills with a value

    // vector<int>v2(3 , 5);

    //print the value
    //here 3 is the size , and every element is 5 fill in the array
    // for(int x : v2){
    //     cout << x << endl;
    // }

    // cout << endl;

    //Initializes vector using initializer list
    //  vector<int>v3 = { 1 , 5 , 7};
     
    //  for(int y : v3){
    //      cout << y <<" ";
    //  }
    //  cout << endl;


     //push the elemnet using operation
     // a) push_back(value)

    //  vector<int>v4 = {34 , 78 , 90};

    //  v4.push_back(100);

    //  // b) insert(pos , count , value)
    //  v4.insert(v4.begin() + 2 ,  3 , 6 );

    //  // insert the value at index 4 with 103
    //  v4.insert(v4.begin() + 4 , 103);

         
    //  for(auto x : v4) cout << x <<" ";


    // Access the elements
    // vector<int>v5 = { 12 , 45 , 90};
    // //using the at(i) function
    // for(int i = 0 ; i < v5.size() ; i++){
    //     cout << v5.at(i) <<" ";
    // }

    // cout << v5[2] << endl;

    // vector<int>v6 = { 10 , 20 , 30};

    // v6[1] = 50;

    // cout <<"Updated value at index 1 " << v6[1] << endl;

    //find the size
    // vector<int>v7 = { 23 , 12 , 89 , 90 , 56};
    // cout << v7.size() << endl;

    // //delete elements
    // vector<char>v8 = {'a' , 'b' , 'c' , 'd' , 'e' ,'f'};

    // //delete the last element 'f'
    // v8.pop_back();

    // //delete the specific element 'c'
    // // using the erase(find(v.begin() , v.end() , 'c' ));
    // // find function exists in the algorithm

    // v8.erase(find(v8.begin() , v8.end() , 'c'));

    // for(int i = 0 ; i < v8.size() ; i++){
    //     cout << v8[i] <<" ";
    // }

    // cout << endl;


    // //vector is empty
    // vector<int>v9;

    // if(v9.empty()){
    //     cout <<"vector  is empty" << endl;
    // }

    // v9.push_back(100);
    // if(!v9.empty()){
    //     cout << "vector is not empty" << endl;
    // }

    //multideminsional vectors
    vector<vector<int>>matrix = {
        {1 , 2 , 3},
        {8 , 9 , 5},
        {3 , 7 , 6}
    };

    for(const auto&row : matrix){
        for(const auto&col : row){
            cout << col <<" ";
        }
        cout << endl;
    }







}