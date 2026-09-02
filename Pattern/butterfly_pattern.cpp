#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cout <<"Enter the number"<< endl;
    cin >>num;

    for(int row = 1 ; row <= num ; row++){

        //star
        for(int col = 1; col <= row ; col++){
             cout <<"* ";
        }

        //spaces
        for(int col = 1 ; col <= 2*num - 2*row ; col++){
            cout <<"  ";
        }

        //star
        for(int col = 1 ; col <= row ; col++){
            cout <<"* ";
        }

        cout << endl;

    }
    for(int row = num - 1 ; row >=1 ; row--){

        //star
        for(int col = 1; col <= row ; col++){
             cout <<"* ";
        }

        //spaces
        for(int col = 1 ; col <= 2*num - 2*row ; col++){
            cout <<"  ";
        }

        //star
        for(int col = 1 ; col <= row ; col++){
            cout <<"* ";
        }

        cout << endl;


    }


}