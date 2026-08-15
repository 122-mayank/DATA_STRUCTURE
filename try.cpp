#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>nums={1 , 2 , 5, 9};

    for(int i = 0 ; i < nums.size() ; i++){
         cout << ceil((double)nums[i] / 3) <<" ";
    }

}