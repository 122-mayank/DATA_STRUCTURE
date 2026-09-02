#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the num"<< endl;
    cin >> num;


    for(int row = 1 ; row <= num ; row = row + 1){

        for(int col = 1 ; col < row ; col = col + 1){
               cout <<"  ";
        }

        for(int col = 1 ; col <= (num - row + 1) ; col = col + 1){
             cout <<col <<" ";
        }

        for(int col = (num - row) ; col >= 1 ; col = col - 1){
             cout <<col <<" ";
        }

        
        cout << endl;
    }

}