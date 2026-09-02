#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the number"<< endl;
    cin >> num;

    for(int row = num ; row >= 1 ; row = row - 1){

        // Print *
        for(int col = 1 ; col <= row ; col = col + 1){
            cout <<"* ";
        }

        //print space
        for(int col = 1 ; col <= 2*num - 2*row ; col = col + 1){
            cout <<"  ";
        }
        //print *
        for(int col = 1 ; col <= row ; col = col + 1){
            cout <<"* ";
        }
        cout << endl;
    }

    for(int row = 1 ; row <= num ; row = row + 1){

        // Print *
        for(int col = 1 ; col <= row ; col = col + 1){
            cout <<"* ";
        }

        //print space
        for(int col = 1 ; col <= 2*num - 2*row ; col = col + 1){
            cout <<"  ";
        }
        //print *
        for(int col = 1 ; col <= row ; col = col + 1){
            cout <<"* ";
        }
        cout << endl;
    }
}

