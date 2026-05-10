#include<bits/stdc++.h>
using namespace std;


int main(){

    unordered_map<int , string>map;

    map[1] ="Shyam";
    map[2] ="Ram";

    auto it = map.find(1);

    if(it != map.end()){
         cout <<"Found!!"<< endl;
    }
    else{
        cout <<"Not found!!"<< endl;
    }



}