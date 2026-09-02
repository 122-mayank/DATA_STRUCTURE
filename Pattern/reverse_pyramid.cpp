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

        for(int col = 1 ; col <= 2 * (num - row ) + 1; col = col + 1){
             cout << "*" <<" ";
        }
        
        cout << endl;
    }

}